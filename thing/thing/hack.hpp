#pragma once
#include "misc.hpp"
#include "visuals.hpp"

class c_hacks
{
private:
	static c_misc* g_misc;
	static c_visuals* g_visuals;
public:
	c_hacks();
	~c_hacks();
	static c_misc* m_misc();
	static c_visuals* m_visuals();
};

extern c_hacks g_hacks;