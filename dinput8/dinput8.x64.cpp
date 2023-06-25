#include "../init.cpp"

HINSTANCE hLThis = 0;
FARPROC p[6];
HINSTANCE hL = 0;

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID) {
  if (reason == DLL_PROCESS_ATTACH) {
    hLThis = hInst;

    char path[MAX_PATH] = {0};
    GetSystemDirectory(path, MAX_PATH);
    strcat_s(path, MAX_PATH, "\\dinput8.dll");
    hL = LoadLibrary(path);
    if (!hL)
      return false;

    Init();
  }

  p[0] = GetProcAddress(hL, "DirectInput8Create");
  p[1] = GetProcAddress(hL, "DllCanUnloadNow");
  p[2] = GetProcAddress(hL, "DllGetClassObject");
  p[3] = GetProcAddress(hL, "DllRegisterServer");
  p[4] = GetProcAddress(hL, "DllUnregisterServer");
  p[5] = GetProcAddress(hL, "GetdfDIJoystick");
  if (reason == DLL_PROCESS_DETACH) {
    FreeLibrary(hL);
    return 1;
  }

  return 1;
}

extern "C" {
FARPROC PA = NULL;
int RunASM();

void PROXY_DirectInput8Create() {
  PA = p[0];
  RunASM();
}
void PROXY_DllCanUnloadNow() {
  PA = p[1];
  RunASM();
}
void PROXY_DllGetClassObject() {
  PA = p[2];
  RunASM();
}
void PROXY_DllRegisterServer() {
  PA = p[3];
  RunASM();
}
void PROXY_DllUnregisterServer() {
  PA = p[4];
  RunASM();
}
void PROXY_GetdfDIJoystick() {
  PA = p[5];
  RunASM();
}
}
