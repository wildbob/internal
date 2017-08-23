#pragma once
#include "instance.hpp"
#include "user_cmd.hpp"

class c_misc
{
private:
public:
	c_misc();
	~c_misc();
	void run(c_cmd* g_cmd);
	void b_hop(c_cmd* g_cmd);
	auto auto_strafe(c_cmd* g_cmd) -> void;
};