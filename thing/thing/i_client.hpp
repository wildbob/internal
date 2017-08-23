#pragma once
#include "window_includes.hpp"
#include "vector.hpp"
#include "utilities.hpp"

class c_chlclient
{
private:
public:
	ClientClass* get_class(void)
	{
		virtual_fn(ClientClass*)(PVOID);
		return g_utils.get_virtual_func< OriginalFn >(this, 8)(this);
	}
};