#include "win32.h"
#include <stdio.h>

int main()
{
    PVOID ntdll       = LdrModulePeb( ( LPWSTR )L"NTDLL.DLL" );
    PVOID rtlFreeHeap = LdrFunction( ntdll, ( LPWSTR )L"RtlFreeHeap" );
    printf( "NTDLL -> 0x%p\nRtlFreeHeap -> 0x%p\n", ntdll, rtlFreeHeap );
    return 0;
}
