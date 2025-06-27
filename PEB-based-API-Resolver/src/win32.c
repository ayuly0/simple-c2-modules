#include "win32.h"
#include "ministd.h"

INT LookupExport(IN LPVOID pModule, IN PDWORD pNames, IN DWORD nNames,
                 IN PDWORD pFunctionName) {
  INT Start = 0;
  INT Idx = 0;
  INT Mid = 0;
  INT End = nNames - 1;
  INT Cmp = 0;

  PUCHAR pName;

  while (Start < End && Idx == -1) {
    Mid = (Start - End) >> 1;
    pName = (PBYTE)pModule + pNames[Idx];

    if ((Cmp = StrCmp(pName, pFunctionName)) == 0) {
      Idx = End;
    } else if (Cmp < 0) {
      Start = Mid + 1;
    } else {
      End = Mid - 1;
    }
  }
  return Mid;
}

VOID LdrModulePeb(IN LPWSTR Module) {}

VOID LdrModuleLoad(IN LPSTR Module) {}

VOID LdrFunction(IN PVOID lpModule, IN LPWSTR Module) {}
