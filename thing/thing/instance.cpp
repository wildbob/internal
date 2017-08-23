#pragma once
#include "instance.hpp"
c_instance g_instance;

c_chlclient* c_instance::g_client = nullptr;
c_engineclient* c_instance::g_engine = nullptr;
c_entitylist* c_instance::g_entitylist = nullptr;
c_surface* c_instance::g_surface = nullptr;
c_panel* c_instance::g_panel = nullptr;
c_debugoverlay* c_instance::g_debugoverlay = nullptr;
c_clientmode* c_instance::g_clientmode = nullptr;
c_globalvars* c_instance::g_globalvars = nullptr;


c_instance::c_instance()
{
	//constructor

}

c_instance::~c_instance()
{
	//destructor
	delete[] g_client;
	delete[] g_engine;
	delete[] g_entitylist;
	delete[] g_panel;
	delete[] g_clientmode;
	delete[] g_globalvars;
}

auto c_instance::m_client() -> c_chlclient*
{
	if (!g_client)
		g_client = g_utils.get_interface<c_chlclient>("client.dll", "VClient");

	return g_client;
}

auto c_instance::m_engine() -> c_engineclient*
{
	if (!g_engine)
		g_engine = g_utils.get_interface<c_engineclient>("engine.dll", "VEngineClient");

	return g_engine;
}

auto c_instance::m_entitylist() -> c_entitylist*
{
	if (!g_entitylist)
		g_entitylist = g_utils.get_interface<c_entitylist>("client.dll", "VClientEntityList");

	return g_entitylist;
}

auto c_instance::m_surface() -> c_surface*
{
	if (!g_surface)
		g_surface = g_utils.get_interface< c_surface >("vguimatsurface.dll", "VGUI_Surface");

	return g_surface;
}

auto c_instance::m_panel()->c_panel*
{
	if (!g_panel)
		g_panel = g_utils.get_interface<c_panel>("vgui2.dll", "VGUI_Panel");

	return g_panel;
}

auto c_instance::m_debugoverlay() -> c_debugoverlay*
{
	if (!g_debugoverlay)
		g_debugoverlay = g_utils.get_interface< c_debugoverlay >("engine.dll", "VDebugOverlay");

	return g_debugoverlay;
}

auto c_instance::m_clientmode() -> c_clientmode*
{
	if (!g_clientmode)
		g_clientmode = **reinterpret_cast<c_clientmode***>((*(uintptr_t**)m_client())[10] + 0x5);

	return g_clientmode;
}

auto c_instance::m_globalvars() -> c_globalvars*
{
	if (!g_globalvars)
		g_globalvars = **reinterpret_cast< c_globalvars*** >((*reinterpret_cast< uintptr_t** >(m_client()))[0] + 0x1B);

	return g_globalvars;
}