#pragma once
#include "window_includes.hpp"
#include "vector.hpp"
#include "utilities.hpp"

class player_info
{
public:
	__int64        unknown;            //0x0000 
	__int64        steamID64;          //0x0008 - SteamID64
	char           szName[128];        //0x0010 - Player Name
	int            userId;             //0x0090 - Unique Server Identifier
	char           szSteamID[20];      //0x0094 - STEAM_X:Y:Z
	char           pad_0x00A8[0x10];   //0x00A8
	unsigned long  iSteamID;           //0x00B8 - SteamID 
	char           unknown2[0x14C];
	int xuidlow;
	int xuidhigh;
};

class c_engineclient
{
public:
	int get_local_player()
	{
		typedef int(__thiscall *get_local_playerfn)(void*);
		return g_utils.get_virtual_func<get_local_playerfn>(this, 12)(this);
	}
	void get_screen_size(int& width, int& height)
	{
		typedef int(__thiscall *OrigFn)(void*, int&, int&);
		g_utils.get_virtual_func<OrigFn>(this, 5)(this, width, height);
	}

	bool get_player_info(int ent_num, player_info *pinfo)
	{
		typedef bool(__thiscall *OrigFn)(void*, int, player_info*);
		return g_utils.get_virtual_func<OrigFn>(this, 8)(this, ent_num, pinfo);
	}
	int get_player_user_id(int UserID)
	{
		using Original = int(__thiscall*)(PVOID, int);
		return g_utils.get_virtual_func<Original>(this, 9)(this, UserID);
	}
	float get_last_time_stamp() {
		typedef float(__thiscall *OrigFn)(void*);
		return g_utils.get_virtual_func<OrigFn>(this, 14)(this);
	}

	void get_view_angles(QAngle& va)
	{
		typedef void(__thiscall *OrigFn)(void*, QAngle&);
		g_utils.get_virtual_func<OrigFn>(this, 18)(this, va);
	}

	void set_view_angles(QAngle& va)
	{
		typedef void(__thiscall *OrigFn)(void*, QAngle&);
		g_utils.get_virtual_func<OrigFn>(this, 19)(this, va);
	}

	int get_max_clients() {
		typedef int(__thiscall *OrigFn)(void*);
		return g_utils.get_virtual_func<OrigFn>(this, 20)(this);
	}

	bool is_in_game() {
		typedef bool(__thiscall *OrigFn)(void*);
		return g_utils.get_virtual_func<OrigFn>(this, 26)(this);
	}

	bool is_connected() {
		typedef bool(__thiscall *OrigFn)(void*);
		return g_utils.get_virtual_func<OrigFn>(this, 27)(this);
	}

	const VMatrix& world_to_screen_matrix()
	{
		typedef const VMatrix&(__thiscall *OrigFn)(void*);
		return g_utils.get_virtual_func<OrigFn>(this, 37)(this);
	}

	void execute_client_cmd(const char* szCmdString) {
		typedef void(__thiscall *OrigFn)(void*, const char *);
		g_utils.get_virtual_func<OrigFn>(this, 108)(this, szCmdString);
	}

	void client_cmd_unrestricted(const char* szCmdString)
	{
		typedef void(__thiscall* OrigFn)(void*, const char*, char);
		g_utils.get_virtual_func<OrigFn>(this, 114)(this, szCmdString, 1);
	}
};