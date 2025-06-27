#ifndef WIN32_H
#define WIN32_H

#define WIN32_LEAN_AND_MEAN

#include <windows.h>

#include "native.h"

#ifdef _WIN64
#define PPEB_PTR __readsqword( 0x60 )
#else
#define PPEB_PTR __readsdword( 0x30 )
#endif

#define NtProcessHeap() NtCurrentTeb()->ProcessEnvironmentBlock->ProcessHeap

#define C_PTR( x ) ( ( LPVOID )x )

INT LookupExport( IN LPVOID pModule, IN PDWORD pNames, IN DWORD nNames, IN PDWORD pFunctionName );

PVOID LdrModulePeb( IN LPWSTR Module );

PVOID LdrModuleLoad( IN LPSTR Module );

PVOID LdrFunction( IN PVOID lpModule, IN LPWSTR Module );

#endif // !WIN32_H
