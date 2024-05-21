#include "pch.h"
#include "ConnectionCaller.h"
#include <iostream>
#include <nlohmann/json_fwd.hpp>
#include <nlohmann/json.hpp>
using namespace nlohmann; 

Connection* New()
{
    Connection* tmp; 
    tmp = new Connection();
    return tmp; 
}

void Dispose(Connection* ptr)
{
    if (ptr != nullptr)
    {
        delete ptr;
        ptr = nullptr;
    }
}

void run_cmd(Connection* ptr, const char* command, const char* password, const char* new_password)
{
    if (ptr != nullptr)
    {
        ptr->run_cmd(std::string(command), std::string(password), std::string(new_password));
    }
}