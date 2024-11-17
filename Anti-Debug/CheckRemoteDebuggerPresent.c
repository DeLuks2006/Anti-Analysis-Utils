#include <windows.h>

int main(void) {
  HANDLE hProc = GetCurrentProcess();
  BOOL xDebuggerPresent = FALSE;

  if (CheckRemoteDebuggerPresent(hProc, &xDebuggerPresent)) {
    if (xDebuggerPresent) {
      MessageBoxW(NULL, L"Detected debugger", L"detected", MB_OK);
    } else {
      MessageBoxW(NULL, L"Didnt find a debugger", L"not detected", MB_OK);
    }
  } else {
    MessageBoxW(NULL, L"Failed to check for debugger", L"failure", MB_OK);
  }

  return 0;
}
