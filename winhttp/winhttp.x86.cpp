#include "../init.cpp"

HINSTANCE hLThis = 0;
FARPROC p[70];
HINSTANCE hL = 0;

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID) {
  if (reason == DLL_PROCESS_ATTACH) {
    hLThis = hInst;

    char path[MAX_PATH] = {0};
    GetSystemDirectory(path, MAX_PATH);
    strcat_s(path, MAX_PATH, "\\winhttp.dll");
    hL = LoadLibrary(path);
    if (!hL)
      return false;

    Init();
  }

  p[0] = GetProcAddress(hL, "DllCanUnloadNow");
  p[1] = GetProcAddress(hL, "DllGetClassObject");
  p[2] = GetProcAddress(hL, "Private1");
  p[3] = GetProcAddress(hL, "SvchostPushServiceGlobals");
  p[4] = GetProcAddress(hL, "WinHttpAddRequestHeaders");
  p[5] = GetProcAddress(hL, "WinHttpAddRequestHeadersEx");
  p[6] = GetProcAddress(hL, "WinHttpAutoProxySvcMain");
  p[7] = GetProcAddress(hL, "WinHttpCheckPlatform");
  p[8] = GetProcAddress(hL, "WinHttpCloseHandle");
  p[9] = GetProcAddress(hL, "WinHttpConnect");
  p[10] = GetProcAddress(hL, "WinHttpConnectionDeletePolicyEntries");
  p[11] = GetProcAddress(hL, "WinHttpConnectionDeleteProxyInfo");
  p[12] = GetProcAddress(hL, "WinHttpConnectionFreeNameList");
  p[13] = GetProcAddress(hL, "WinHttpConnectionFreeProxyInfo");
  p[14] = GetProcAddress(hL, "WinHttpConnectionFreeProxyList");
  p[15] = GetProcAddress(hL, "WinHttpConnectionGetNameList");
  p[16] = GetProcAddress(hL, "WinHttpConnectionGetProxyInfo");
  p[17] = GetProcAddress(hL, "WinHttpConnectionGetProxyList");
  p[18] = GetProcAddress(hL, "WinHttpConnectionSetPolicyEntries");
  p[19] = GetProcAddress(hL, "WinHttpConnectionSetProxyInfo");
  p[20] = GetProcAddress(hL, "WinHttpConnectionUpdateIfIndexTable");
  p[21] = GetProcAddress(hL, "WinHttpCrackUrl");
  p[22] = GetProcAddress(hL, "WinHttpCreateProxyResolver");
  p[23] = GetProcAddress(hL, "WinHttpCreateUrl");
  p[24] = GetProcAddress(hL, "WinHttpDetectAutoProxyConfigUrl");
  p[25] = GetProcAddress(hL, "WinHttpFreeProxyResult");
  p[26] = GetProcAddress(hL, "WinHttpFreeProxyResultEx");
  p[27] = GetProcAddress(hL, "WinHttpFreeProxySettings");
  p[28] = GetProcAddress(hL, "WinHttpGetDefaultProxyConfiguration");
  p[29] = GetProcAddress(hL, "WinHttpGetIEProxyConfigForCurrentUser");
  p[30] = GetProcAddress(hL, "WinHttpGetProxyForUrl");
  p[31] = GetProcAddress(hL, "WinHttpGetProxyForUrlEx");
  p[32] = GetProcAddress(hL, "WinHttpGetProxyForUrlEx2");
  p[33] = GetProcAddress(hL, "WinHttpGetProxyForUrlHvsi");
  p[34] = GetProcAddress(hL, "WinHttpGetProxyResult");
  p[35] = GetProcAddress(hL, "WinHttpGetProxyResultEx");
  p[36] = GetProcAddress(hL, "WinHttpGetProxySettingsVersion");
  p[37] = GetProcAddress(hL, "WinHttpGetTunnelSocket");
  p[38] = GetProcAddress(hL, "WinHttpOpen");
  p[39] = GetProcAddress(hL, "WinHttpOpenRequest");
  p[40] = GetProcAddress(hL, "WinHttpPacJsWorkerMain");
  p[41] = GetProcAddress(hL, "WinHttpProbeConnectivity");
  p[42] = GetProcAddress(hL, "WinHttpQueryAuthSchemes");
  p[43] = GetProcAddress(hL, "WinHttpQueryDataAvailable");
  p[44] = GetProcAddress(hL, "WinHttpQueryHeaders");
  p[45] = GetProcAddress(hL, "WinHttpQueryOption");
  p[46] = GetProcAddress(hL, "WinHttpReadData");
  p[47] = GetProcAddress(hL, "WinHttpReadProxySettings");
  p[48] = GetProcAddress(hL, "WinHttpReadProxySettingsHvsi");
  p[49] = GetProcAddress(hL, "WinHttpReceiveResponse");
  p[50] = GetProcAddress(hL, "WinHttpResetAutoProxy");
  p[51] = GetProcAddress(hL, "WinHttpSaveProxyCredentials");
  p[52] = GetProcAddress(hL, "WinHttpSendRequest");
  p[53] = GetProcAddress(hL, "WinHttpSetCredentials");
  p[54] = GetProcAddress(hL, "WinHttpSetDefaultProxyConfiguration");
  p[55] = GetProcAddress(hL, "WinHttpSetOption");
  p[56] = GetProcAddress(hL, "WinHttpSetProxySettingsPerUser");
  p[57] = GetProcAddress(hL, "WinHttpSetSecureLegacyServersAppCompat");
  p[58] = GetProcAddress(hL, "WinHttpSetStatusCallback");
  p[59] = GetProcAddress(hL, "WinHttpSetTimeouts");
  p[60] = GetProcAddress(hL, "WinHttpTimeFromSystemTime");
  p[61] = GetProcAddress(hL, "WinHttpTimeToSystemTime");
  p[62] = GetProcAddress(hL, "WinHttpWebSocketClose");
  p[63] = GetProcAddress(hL, "WinHttpWebSocketCompleteUpgrade");
  p[64] = GetProcAddress(hL, "WinHttpWebSocketQueryCloseStatus");
  p[65] = GetProcAddress(hL, "WinHttpWebSocketReceive");
  p[66] = GetProcAddress(hL, "WinHttpWebSocketSend");
  p[67] = GetProcAddress(hL, "WinHttpWebSocketShutdown");
  p[68] = GetProcAddress(hL, "WinHttpWriteData");
  p[69] = GetProcAddress(hL, "WinHttpWriteProxySettings");
  if (reason == DLL_PROCESS_DETACH) {
    FreeLibrary(hL);
    return 1;
  }

  return 1;
}

extern "C" {
void __declspec(naked) PROXY_DllCanUnloadNow() {
  __asm
  {			jmp p[0 * 4]
  }
}
void __declspec(naked) PROXY_DllGetClassObject() {
  __asm
  {			jmp p[1 * 4]
  }
}
void __declspec(naked) PROXY_Private1() {
  __asm
  {			jmp p[2 * 4]
  }
}
void __declspec(naked) PROXY_SvchostPushServiceGlobals() {
  __asm
  {			jmp p[3 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpAddRequestHeaders() {
  __asm
  {			jmp p[4 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpAddRequestHeadersEx() {
  __asm
  {			jmp p[5 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpAutoProxySvcMain() {
  __asm
  {			jmp p[6 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpCheckPlatform() {
  __asm
  {			jmp p[7 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpCloseHandle() {
  __asm
  {			jmp p[8 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpConnect() {
  __asm
  {			jmp p[9 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpConnectionDeletePolicyEntries() {
  __asm
  {			jmp p[10 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpConnectionDeleteProxyInfo() {
  __asm
  {			jmp p[11 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpConnectionFreeNameList() {
  __asm
  {			jmp p[12 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpConnectionFreeProxyInfo() {
  __asm
  {			jmp p[13 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpConnectionFreeProxyList() {
  __asm
  {			jmp p[14 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpConnectionGetNameList() {
  __asm
  {			jmp p[15 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpConnectionGetProxyInfo() {
  __asm
  {			jmp p[16 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpConnectionGetProxyList() {
  __asm
  {			jmp p[17 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpConnectionSetPolicyEntries() {
  __asm
  {			jmp p[18 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpConnectionSetProxyInfo() {
  __asm
  {			jmp p[19 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpConnectionUpdateIfIndexTable() {
  __asm
  {			jmp p[20 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpCrackUrl() {
  __asm
  {			jmp p[21 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpCreateProxyResolver() {
  __asm
  {			jmp p[22 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpCreateUrl() {
  __asm
  {			jmp p[3 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpDetectAutoProxyConfigUrl() {
  __asm
  {			jmp p[24 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpFreeProxyResult() {
  __asm
  {			jmp p[25 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpFreeProxyResultEx() {
  __asm
  {			jmp p[26 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpFreeProxySettings() {
  __asm
  {			jmp p[27 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpGetDefaultProxyConfiguration() {
  __asm
  {			jmp p[28 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpGetIEProxyConfigForCurrentUser() {
  __asm
  {			jmp p[29 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpGetProxyForUrl() {
  __asm
  {			jmp p[30 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpGetProxyForUrlEx() {
  __asm
  {			jmp p[31 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpGetProxyForUrlEx2() {
  __asm
  {			jmp p[32 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpGetProxyForUrlHvsi() {
  __asm
  {			jmp p[33 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpGetProxyResult() {
  __asm
  {			jmp p[34 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpGetProxyResultEx() {
  __asm
  {			jmp p[35 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpGetProxySettingsVersion() {
  __asm
  {			jmp p[36 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpGetTunnelSocket() {
  __asm
  {			jmp p[37 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpOpen() {
  __asm
  {			jmp p[38 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpOpenRequest() {
  __asm
  {			jmp p[39 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpPacJsWorkerMain() {
  __asm
  {			jmp p[40 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpProbeConnectivity() {
  __asm
  {			jmp p[41 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpQueryAuthSchemes() {
  __asm
  {			jmp p[42 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpQueryDataAvailable() {
  __asm
  {			jmp p[43 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpQueryHeaders() {
  __asm
  {			jmp p[44 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpQueryOption() {
  __asm
  {			jmp p[45 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpReadData() {
  __asm
  {			jmp p[46 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpReadProxySettings() {
  __asm
  {			jmp p[47 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpReadProxySettingsHvsi() {
  __asm
  {			jmp p[48 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpReceiveResponse() {
  __asm
  {			jmp p[49 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpResetAutoProxy() {
  __asm
  {			jmp p[50 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpSaveProxyCredentials() {
  __asm
  {			jmp p[51 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpSendRequest() {
  __asm
  {			jmp p[52 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpSetCredentials() {
  __asm
  {			jmp p[53 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpSetDefaultProxyConfiguration() {
  __asm
  {			jmp p[54 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpSetOption() {
  __asm
  {			jmp p[55 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpSetProxySettingsPerUser() {
  __asm
  {			jmp p[56 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpSetSecureLegacyServersAppCompat() {
  __asm
  {			jmp p[57 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpSetStatusCallback() {
  __asm
  {			jmp p[58 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpSetTimeouts() {
  __asm
  {			jmp p[59 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpTimeFromSystemTime() {
  __asm
  {			jmp p[60 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpTimeToSystemTime() {
  __asm
  {			jmp p[61 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpWebSocketClose() {
  __asm
  {			jmp p[62 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpWebSocketCompleteUpgrade() {
  __asm
  {			jmp p[63 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpWebSocketQueryCloseStatus() {
  __asm
  {			jmp p[64 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpWebSocketReceive() {
  __asm
  {			jmp p[65 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpWebSocketSend() {
  __asm
  {			jmp p[66 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpWebSocketShutdown() {
  __asm
  {			jmp p[67 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpWriteData() {
  __asm
  {			jmp p[68 * 4]
  }
}
void __declspec(naked) PROXY_WinHttpWriteProxySettings() {
  __asm
  {			jmp p[69 * 4]
  }
}
}
