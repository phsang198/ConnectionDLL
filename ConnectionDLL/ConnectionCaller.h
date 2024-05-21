#pragma once
#include "Connection.h"      
#include <comdef.h>
using namespace ConnectionAPI;

#ifdef __cplusplus
extern "C" {
#endif

	extern __declspec(dllexport) Connection* New();

	extern __declspec(dllexport) void Dispose(Connection* ptr);

	extern __declspec(dllexport) void run_cmd(Connection* ptr, const char* command, const char* password, const char* new_password);

#ifdef __cplusplus
}
#endif