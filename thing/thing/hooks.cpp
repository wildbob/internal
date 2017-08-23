#pragma once
#include "hooks.hpp"

c_hookmanager* hooks::panel_vmt = nullptr;
c_hookmanager* hooks::clientmode_vmt = nullptr;

auto hooks::run() -> void
{
	if (!panel_vmt)
		panel_vmt = new c_hookmanager((PDWORD*)g_instance.m_panel());

	paint_traverse_fn = (oPaintTraverse)panel_vmt->HookMethod((DWORD)hk_paint_traverse, 41);

	panel_vmt->ReHook();

	if (!clientmode_vmt)
		clientmode_vmt = new c_hookmanager((PDWORD*)g_instance.m_clientmode());

	clientmode_vmt->HookMethod((DWORD)hk_create_move, 24);

	clientmode_vmt->ReHook();
}