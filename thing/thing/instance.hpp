#pragma once
#include "window_includes.hpp"
#include "i_client.hpp"
#include "i_engine.hpp"
#include "i_entitylist.hpp"
#include "i_surface.hpp"
#include "i_panel.hpp"
#include "i_debugoverlay.hpp"
#include "i_clientmode.hpp"
#include "i_globals.hpp"

class c_instance
{
private:
	//
	static c_chlclient* g_client;
	static c_engineclient* g_engine;
	static c_entitylist* g_entitylist;
	static c_surface* g_surface;
	static c_panel* g_panel;
	static c_debugoverlay* g_debugoverlay;
	static c_clientmode* g_clientmode;
	static c_globalvars* g_globalvars;
	//
public:
	c_instance();
	~c_instance();
	static c_chlclient* m_client();
	static c_engineclient* m_engine();
	static c_entitylist* m_entitylist();
	static c_surface* m_surface();
	static c_panel* m_panel();
	static c_debugoverlay* m_debugoverlay();
	static c_clientmode* m_clientmode();
	static c_globalvars* m_globalvars();
};

extern c_instance g_instance;