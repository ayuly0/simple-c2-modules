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
