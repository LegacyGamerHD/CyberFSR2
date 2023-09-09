#include "pch.h"
#include "Logger.h"

HMODULE dllModule;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        dllModule = hModule;
        CyberFSR::Logger::init();
        
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        CyberFSR::Logger::cleanup();
        break;
    }
    return TRUE;
}

