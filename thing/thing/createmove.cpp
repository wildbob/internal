#include "hooks.hpp"
#include "globals.hpp"
#include "hack.hpp"

bool __stdcall hooks::hk_create_move(float flInputSampleTime, c_cmd* cmd)
{
	if (!cmd)
		return false;

	if (!cmd->command_number)
		return false;

	DWORD* framePointer;
	__asm mov framePointer, ebp;
	*(bool*)(*framePointer - 0x1C) = globals::send_packet;

	g_hacks.m_misc( )->run( cmd );

	return false;
}