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
void __declspec(naked) PROXY_DirectInput8Create() {
  __asm
  {			jmp p[0 * 4]
  }
}
void __declspec(naked) PROXY_DllCanUnloadNow() {
  __asm
  {			jmp p[1 * 4]
  }
}
void __declspec(naked) PROXY_DllGetClassObject() {
  __asm
  {			jmp p[2 * 4]
  }
}
void __declspec(naked) PROXY_DllRegisterServer() {
  __asm
  {			jmp p[3 * 4]
  }
}
void __declspec(naked) PROXY_DllUnregisterServer() {
  __asm
  {			jmp p[4 * 4]
  }
}
void __declspec(naked) PROXY_GetdfDIJoystick() {
  __asm
  {			jmp p[5 * 4]
  }
}
}
