#include "pch.h"
#include "Connection.h"
#include <thread>
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace ConnectionAPI;

Connection::Connection() {}

Connection::~Connection() {}

void press_key(int virtual_key)
{
    keybd_event(virtual_key, 0, KEYEVENTF_EXTENDEDKEY, 0);
    keybd_event(virtual_key, 0, KEYEVENTF_KEYUP, 0);
}
char upcase(char c) {
    if (std::islower(c)) {
        return std::toupper(c);
    }
    return c;
}
void myThreadFunction(std::string password, std::string new_password)
{
    std::this_thread::sleep_for(std::chrono::seconds(4));

    for (int i = 0; i < password.length(); i++)
        press_key(upcase(password[i]));
    press_key(VK_RETURN);

    if (new_password != "")
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        for (int i = 0; i < password.length(); i++)
            press_key(upcase(password[i]));
        press_key(VK_RETURN);
    }
}
void Connection::run_cmd(std::string command, std::string password, std::string new_password)
{
    std::thread myThread(myThreadFunction,password, new_password);

    myThread.detach();
    system(command.c_str());
}
