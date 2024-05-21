#include "pch.h"
#include "RegistryCaller.h"

LPCWSTR ConstChar2Lpcwstr(const char* str)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);

    wchar_t* wstr = new wchar_t[len];
    MultiByteToWideChar(CP_UTF8, 0, str, -1, wstr, len);

    LPCWSTR lpwstr = wstr;

    delete[] wstr;
    return lpwstr;
}

BOOL deleteRegistry(const char* _path, const char* _key)
{
    try {
        LPCWSTR path = ConstChar2Lpcwstr(_path);
        LPCWSTR name = ConstChar2Lpcwstr(_key);

        // Open the key 
        HKEY key;
        LONG result = RegOpenKeyEx(HKEY_CURRENT_USER, path, 0, KEY_WRITE, &key);
        if (result != ERROR_SUCCESS)
        {
            std::cout << "Error: Unable to open key." << std::endl;
            system("pause");
            return FALSE;
        }

        // Delete exist key
        result = RegDeleteValue(key, name);
        if (result != ERROR_SUCCESS)
        {
            std::cout << "Error: Unable to delete value. Or key not exist" << std::endl;
            system("pause");
            return FALSE;
        }

        // Close the key.
        RegCloseKey(key);

        std::cout << "delete key successfully." << std::endl;
        return TRUE; 
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        system("pause");
        return FALSE ;
    }
    return FALSE;
}

BOOL addRegistry(const char* _path, const char* _key, const char* _value)
{
    try {
        LPCWSTR path = ConstChar2Lpcwstr(_path);
        LPCWSTR name = ConstChar2Lpcwstr(_key);
        LPCWSTR _data = ConstChar2Lpcwstr(_value);

        // Open the key 
        HKEY key;
        LONG result = RegCreateKeyEx(HKEY_CURRENT_USER, path, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &key, NULL);
        if (result != ERROR_SUCCESS)
        {
            std::cout << "Error: Unable to open or create key." << std::endl;
            system("pause");
            return FALSE;
        }

        // Add the file to the key.

        std::wstring data(_data);
        result = RegSetValueEx(key, name, 0, REG_SZ, reinterpret_cast<const BYTE*>(data.c_str()), static_cast<DWORD>(data.length() * sizeof(wchar_t)));
        if (result != ERROR_SUCCESS)
        {
            std::cout << "Error: Unable to add value." << std::endl;
            system("pause");
            return FALSE;
        }

        // Close the key.
        RegCloseKey(key);

        std::cout << "key added to Registry successfully." << std::endl;
        return TRUE; 
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
        system("pause");
        return FALSE;
    }
    return FALSE;

}
