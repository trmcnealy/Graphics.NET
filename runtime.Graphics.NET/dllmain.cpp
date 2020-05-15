
#include <windows.h>

BOOL WINAPI DllMain(HANDLE hModule, const DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch(ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        {
            DisableThreadLibraryCalls(static_cast<HINSTANCE>(hModule));

            break;
        }
        case DLL_PROCESS_DETACH:
        {
            break;
        }
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        default: break;
    }
    return TRUE;
}
