#pragma once
#include "window_includes.hpp"
#include "vector.hpp"
#include "utilities.hpp"
typedef unsigned long c_handle;
class c_entity;

class c_entitylist
{
public:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual c_entity *		get_entity(int entnum);
	virtual c_entity *		get_entity_handle(c_handle hEnt) = 0;
	virtual int					num_of_entites(bool bIncludeNonNetworkable) = 0;
	virtual int					get_hightest_entity_index(void);
	virtual void				set_max_entities(int maxents);
	virtual int					get_max_entities();
};