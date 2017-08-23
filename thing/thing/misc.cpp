#pragma once
#include "misc.hpp"
#include "entity.hpp"
#include "utilities.hpp"

c_misc::c_misc()
{

}

c_misc::~c_misc()
{

}



void c_misc::b_hop(c_cmd* g_cmd)
{
	auto local_player = c_entity::get_local_player();

	static auto bJumped = false;
	static auto bFake = false;
	if (!bJumped && bFake)
	{
		bFake = false;
		g_cmd->buttons |= IN_JUMP;
	}
	else if (g_cmd->buttons & IN_JUMP)
	{
		if (local_player->get_flags() & FL_ONGROUND)
		{
			bJumped = true;
			bFake = true;
		}
		else
		{
			g_cmd->buttons &= ~IN_JUMP;
			bJumped = false;
		}
	}
	else
	{
		bJumped = false;
		bFake = false;
	}
}

auto c_misc::auto_strafe(c_cmd* g_cmd) -> void
{
	auto local_player = c_entity::get_local_player();


	static float move = 650.f;
	float s_move = move * 0.5065f;
	if ((local_player->get_flags() & FL_ONGROUND)) return;

	g_cmd->forwardmove = move * 0.015f;
	g_cmd->sidemove += static_cast<float>(((g_cmd->tick_count % 2) * 2) - 1) * s_move;

	if (g_cmd->mousedx)
		g_cmd->sidemove = static_cast<float>(g_utils.clamp(g_cmd->mousedx, -1, 1)) * s_move;

	static auto strafe = g_cmd->viewangles.y;

	float rt = g_cmd->viewangles.y, rotation;
	rotation = strafe - rt;

	if (rotation < -g_instance.m_globalvars( )->interval_per_tick)
		g_cmd->sidemove = -s_move;

	if (rotation > g_instance.m_globalvars( )->interval_per_tick)
		g_cmd->sidemove = s_move;

	strafe = rt;
}

void c_misc::run(c_cmd* g_cmd)
{
	b_hop(g_cmd);
	auto_strafe(g_cmd);
}

