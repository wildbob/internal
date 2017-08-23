#pragma once
#include "window_includes.hpp"
#include "vector.hpp"
#include "utilities.hpp"

class c_panel
{
public:
	const char *get_name(unsigned int vguiPanel)
	{
		typedef const char *(__thiscall* OrigFn)(void*, unsigned int);
		return g_utils.get_virtual_func<OrigFn>(this, 36)(this, vguiPanel);
	}
};