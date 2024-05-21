using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ConnectionTest
{
    public class MyConnection
    {
        private const string dllPath = @"D:\OUTSOURCE\CONNECT\ConnectionDLL\ConnectionDLL\Win32\Release\ConnectionDLL.dll";

        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern IntPtr New();

        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void Dispose(IntPtr ptr);

        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void GetH(IntPtr ptr, string sURL, string header, int connectTimeOut = 0, int timeOut = 0);

        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void PostH(IntPtr ptr, string sURL, string header, string body, int connectTimeOut = 0, int timeOut = 0);


        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void Get(IntPtr ptr, string sURL, int connectTimeOut = 0, int timeOut = 0);

        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void Post(IntPtr ptr, string sURL, string body, int connectTimeOut = 0, int timeOut = 0);

        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.Bool)]
        public static extern bool addHeader(IntPtr ptr, string key, string value);

        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern int getResponseStatusCode(IntPtr ptr);

        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string getResponseData(IntPtr ptr);


    }
    public class MyRegistry
    {
        private const string dllPath = @"D:\OUTSOURCE\CONNECT\ConnectionDLL\ConnectionDLL\Win32\Release\ConnectionDLL.dll";
        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void addRegistry(string _path, string _key, string _value);

        [DllImport(dllPath, CallingConvention = CallingConvention.Cdecl)]
        public static extern void deleteRegistry(string _path, string _key);
    }
        class Program
    {
        static void Main(string[] args)
        {
            try
            {
                //IntPtr connectionPtr = MyConnection.New();

                ////bool resAddheader = MyConnection.addHeader(connectionPtr,"Content-Type", "application/json");
                //string header = "{\"Content-Type\" : \"application/json\"}"; 
                //MyConnection.GetH(connectionPtr, "https://jsonplaceholder.typicode.com/todos/1", header,1000,1000);
                //int status_code = MyConnection.getResponseStatusCode(connectionPtr); 
                //string responseData = MyConnection.getResponseData(connectionPtr);
                //Console.WriteLine(responseData);

                //MyConnection.PostH(connectionPtr, "https://jsonplaceholder.typicode.com/todos/1", header, "{\"title\":\"foo\",\"body\":\"bar\",\"userId\":2}", 1000, 1000);
                //status_code = MyConnection.getResponseStatusCode(connectionPtr);
                //responseData = MyConnection.getResponseData(connectionPtr);

                //MyConnection.Dispose(connectionPtr);

                //MyRegistry.addRegistry("SOFTWARE\\Google\\Chrome\\Extensions\\test\\abc", "toolmf", "1"); 
                MyRegistry.deleteRegistry("SOFTWARE\\Google\\Chrome\\Extensions\\test\\abc", "toolmf" ); 
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error: " + ex.Message);
            }
        }

    }
}
