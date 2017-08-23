#pragma once
#include "entity.hpp"
#include "drawings.hpp"

struct b_box
{
	int x, y, w, h;
};

class c_visuals
{
private:
	auto boundingbox(c_entity* entity, b_box box) -> void;
	auto healthbar(c_entity* entity, b_box box) -> void;
public:
	c_visuals();
	~c_visuals();
	auto run() -> void;
	auto get_box(c_entity* entity) -> b_box;
};

