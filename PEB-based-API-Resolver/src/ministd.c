#include "ministd.h"

SIZE_T StrLenA( IN LPCSTR pszStr )
{
    if ( pszStr == NULL )
    {
        return 0;
    }

    LPCSTR pszStr2 = pszStr;

    for ( ; *pszStr2; ++pszStr2 )
        ;

    return pszStr2 - pszStr;
}

SIZE_T StrLenW( IN LPCWSTR pszwStr )
{
    LPCWSTR pszwStr2 = pszwStr;

    for ( ; *pszwStr2; ++pszwStr2 )
        ;

    return pszwStr2 - pszwStr;
}

INT StrCmp( IN PVOID Str1, IN PVOID Str2 )
{
    PUCHAR pStr1 = ( PUCHAR )Str1;
    PUCHAR pStr2 = ( PUCHAR )Str2;
    while ( *( PUCHAR )Str1 && *( PUCHAR )Str1 == *( PUCHAR )Str2 )
    {
        pStr1++;
        pStr2++;
    }
    return *( PUCHAR )Str1 - *( PUCHAR )Str2;
}

INT StrCmpA( IN LPCSTR Str1, IN LPCSTR Str2 )
{
    for ( ; *Str1 == *Str2; Str1++, Str2++ )
    {
        if ( *Str1 == '\0' )
        {
            return 0;
        }
    }
    return ( ( *( LPCSTR )Str1 < *( LPCSTR )Str2 ) ? -1 : 1 );
}

INT StrCmpW( IN LPWSTR Str1, IN LPWSTR Str2 )
{
    for ( ; *Str1 == *Str2; Str1++, Str2++ )
    {
        if ( *Str1 == '\0' )
        {
            return 0;
        }
    }
    return ( ( *( LPWSTR )Str1 < *( LPWSTR )Str2 ) ? -1 : 1 );
}
