#include "hack.hpp"

c_hacks g_hacks;

c_visuals* c_hacks::g_visuals = nullptr;
c_misc* c_hacks::g_misc = nullptr; 

c_hacks::c_hacks()
{

}

c_hacks::~c_hacks()
{

}

auto c_hacks::m_misc() -> c_misc*
{
	if (!g_misc)
		g_misc = new c_misc;

	return g_misc;
}

auto c_hacks::m_visuals() -> c_visuals*
{
	if (!g_visuals)
		g_visuals = new c_visuals;

	return g_visuals;
}
