#pragma once
#include "hooks.hpp"
#include "hack.hpp"
#include "drawings.hpp"
#include "menu.hpp"


oPaintTraverse paint_traverse_fn;

void __fastcall hooks::hk_paint_traverse(PVOID thisptr, int edx, unsigned int VGUIPanel, bool forceRepaint, bool allowForce)
{
	paint_traverse_fn(thisptr, VGUIPanel, forceRepaint, allowForce);

	if (!strcmp("MatSystemTopPanel", g_instance.m_panel()->get_name(VGUIPanel)))
	{
		g_drawings.draw_rect(50, 50, 50, 50, Color(255, 255, 255, 255));

		g_hacks.m_visuals( )->run( );

		g_menu.draw();
	}
}