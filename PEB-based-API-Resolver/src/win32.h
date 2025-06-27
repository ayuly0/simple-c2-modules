#ifndef WIN32_H
#define WIN32_H

#include <windows.h>

#include "native.h"

#ifdef _WIN64
#define PPEB_PTR __readsqword( 0x60 )
#else
#define PPEB_PTR __readsdword( 0x30 )
#endif

#define NtProcessHeap() NtCurrentTeb()->ProcessEnvironmentBlock->ProcessHeap

INT LookupExport( IN LPVOID pModule, IN PDWORD pNames, IN DWORD nNames, IN PDWORD pFunctionName );

VOID LdrModulePeb( IN LPWSTR Module );

VOID LdrModuleLoad( IN LPSTR Module );

VOID LdrFunction( IN PVOID lpModule, IN LPWSTR Module );

#endif // !WIN32_H
