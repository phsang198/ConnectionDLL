#pragma once
#define CONNECTIONAPI_API __declspec(dllexport)
#include <string>
namespace ConnectionAPI {

    class CONNECTIONAPI_API Connection {
    public:
        Connection();
        ~Connection();

        void run_cmd(std::string command, std::string password, std::string new_password);
    };

}
