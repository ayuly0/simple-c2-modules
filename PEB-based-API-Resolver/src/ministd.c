#include "ministd.h"

INT StrCmp(IN PVOID Str1, IN PVOID Str2) {
  PUCHAR pStr1 = (PUCHAR)Str1;
  PUCHAR pStr2 = (PUCHAR)Str2;
  while (*(PUCHAR)Str1 && *(PUCHAR)Str1 == *(PUCHAR)Str2) {
    pStr1++;
    pStr2++;
  }
  return *(PUCHAR)Str1 - *(PUCHAR)Str2;
}

INT StrCmpA(IN LPCSTR Str1, IN LPCSTR Str2) {
  for (; *Str1 == *Str2; Str1++, Str2++) {
    if (*Str1 == '\0')
      return 0;
  }
  return ((*(LPCSTR)Str1 < *(LPCSTR)Str2) ? -1 : 1);
}

INT StrCmpW(IN LPWSTR Str1, IN LPWSTR Str2) {
  for (; *Str1 == *Str2; Str1++, Str2++) {
    if (*Str1 == '\0')
      return 0;
  }
  return ((*(LPWSTR)Str1 < *(LPWSTR)Str2) ? -1 : 1);
}
