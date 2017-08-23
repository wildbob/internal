#pragma once
#include "window_includes.hpp"
#include "vector.hpp"
#include "utilities.hpp"

class c_globalvars
{
public:
	float	realtime;
	int		framecount;
	float	absoluteframetime;
	float	unknown;
	float	curtime;
	float	frametime;
	int		maxclients;
	int		tickcount;
	float	interval_per_tick;
	float	interpolation_amount;
};