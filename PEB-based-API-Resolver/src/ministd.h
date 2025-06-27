#ifndef MINI_STD_H
#define MINI_STD_H

#include <windows.h>

#include "native.h"

#define MemCopy         __builtin_memcpy
#define MemSet          __stosb
#define MemZero( p, l ) __stosb( p, 0, l )

INT StrCmp( IN PVOID, IN PVOID );

INT StrCmpA( IN LPCSTR, IN LPCSTR );

INT StrCmpW( IN LPWSTR, IN LPWSTR );

#endif // !MINI_STD_H
