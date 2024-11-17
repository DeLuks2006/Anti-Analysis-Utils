#include <windows.h>

int main(void) {
  if (IsDebuggerPresent() != 0) {
    MessageBoxW(NULL, L"Debugger Detected", L"DETECTED", MB_OK);
  } else {
    MessageBoxW(NULL, L"No Debugger Detected", L"NOT DETECTED", MB_OK);
  }
  return 0;
}
