#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

bool CheckForSoftwareBP(void* pMemory, size_t SizeToCheck) {
  unsigned char* pTmp = (unsigned char*)pMemory;
  for (size_t i = 0; i < SizeToCheck, i++) {
    if (pTmp[i] == 0xCC) {
      return true;
    } else if (pTmp[i] == 0xCD && pTmp[i+1] == 0x03) {
      return true;
    } else if (pTmp[i] == 0x0F && pTmp[i+1] == 0x0B) {
      return true;
    }
  }
  return false;
}

int main(void) {
  size_t size = 256;
  void* pMemory = malloc(size);
  if (pMemory == NULL) {
    MessageBoxW(NULL, L"Failed to alloc memory", L"failure", MB_OK);
  }

  memset(pMemory, 0, size);

  if (CheckForSoftwareBP(pMemory, size)) {
    MessageBoxW(NULL, L"Debugger detected", L"detected", MB_OK);
  } else {
    MessageBoxW(NULL, L"Debugger not detected", L"not detected", MB_OK);
  }

  free(pMemory);
  return 0;
}
