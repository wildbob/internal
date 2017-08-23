#pragma once
#include "instance.hpp"
#include "netvar_manager.hpp"
#include <process.h>
#include "hooks.hpp"

void AttachDebugConsole(void)
{
	if (FreeConsole())
	{
		if (!AllocConsole())
			return;
	}
	else if (!AllocConsole())
		return;

	SetConsoleTitleA("dev console");

	FILE* pCon = nullptr;
	freopen_s(&pCon, "CONOUT$", "w", stdout);
}

void intialize(PVOID pParam)
{
	AttachDebugConsole();

	c_netvars::Instance( )->CreateDatabase();
	hooks::run();
}



BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		_beginthread(intialize, 0, NULL);
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}