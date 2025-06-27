#include "win32.h"
#include "ministd.h"

INT LookupExport( IN LPVOID pModule, IN PDWORD pNames, IN DWORD nNames, IN PDWORD pFunctionName )
{
    INT Start = 0;
    INT Idx   = 0;
    INT Mid   = 0;
    INT End   = nNames - 1;
    INT Cmp   = 0;

    PUCHAR pName;

    while ( Start < End && Idx == -1 )
    {
        Mid   = ( Start - End ) >> 1;
        pName = ( PBYTE )pModule + pNames[ Idx ];

        if ( ( Cmp = StrCmp( pName, pFunctionName ) ) == 0 )
        {
            Idx = End;
        }
        else if ( Cmp < 0 )
        {
            Start = Mid + 1;
        }
        else
        {
            End = Mid - 1;
        }
    }
    return Mid;
}

PVOID LdrModulePeb( IN LPWSTR Module )
{
    PPEB Peb                  = NULL;
    PLDR_DATA_TABLE_ENTRY Ldr = NULL;
    PLIST_ENTRY Hdr           = NULL;
    LPWSTR Name               = { 0 };
    ULONG Idx                 = 0;

    Name = HeapAlloc( NtProcessHeap(), HEAP_ZERO_MEMORY, MAX_PATH );

    Peb = NtCurrentTeb()->ProcessEnvironmentBlock;
    Hdr = &Peb->Ldr->InLoadOrderModuleList;

    for ( PLIST_ENTRY Ent = Hdr->Flink; Hdr != Ent; Ent = Ent->Flink )
    {
        Ldr = C_PTR( Ent );
        if ( Ldr->BaseDllName.Length > 260 )
        {
            return NULL;
        }

        MemCopy( Name, Ldr->BaseDllName.Buffer, Ldr->BaseDllName.Length );

        do
        {
            if ( Idx < Ldr->BaseDllName.Length )
            {
                if ( Name[ Idx ] >= 'a' )
                {
                    Name[ Idx ] -= 0x20;
                }
            }
            else
            {
                break;
            }
            Idx++;
        } while ( 1 );
        Idx = 0;

        if ( ( StrCmpW( Name, Module ) == 0 ) || Module == NULL )
        {
            return Ldr->DllBase;
        }

        MemZero( ( LPSTR )Name, MAX_PATH );
    }

    if ( Name )
    {
        MemZero( ( LPSTR )Name, MAX_PATH );
        HeapFree( NtProcessHeap(), HEAP_ZERO_MEMORY, Name );
        Name = NULL;
    }
    return NULL;
}

PVOID LdrModuleLoad( IN LPSTR Module )
{
}

PVOID LdrFunction( IN PVOID lpModule, IN LPWSTR Module )
{
}
