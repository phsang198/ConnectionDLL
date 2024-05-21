#pragma once
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

	extern __declspec(dllexport) BOOL addRegistry(const char* _path, const char* _key, const char* _value);
	extern __declspec(dllexport) BOOL deleteRegistry(const char* _path, const char* _key);

#ifdef __cplusplus
}
#endif