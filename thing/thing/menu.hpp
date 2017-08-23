#pragma once
#include "entity.hpp"

class c_base
{
public:
	std::string name;
	Vector2D position;
	Vector2D size;
	Color color;
	bool should_draw = false;
	int items = 0;
	c_base* parent = nullptr;
	c_base() {}
	c_base(std::string title, Vector2D sizes, bool draw, Color colors, Vector2D position)
		: name(title), should_draw(draw), size(sizes), color(colors)
	{
		set_position(position);
	}
	virtual void draw() = 0;
	void set_parent(c_base* cool)
	{
		parent = cool;
	}
	void set_position(Vector2D position2)
	{
		position = position2;
	}
};


class c_window : public c_base
{
public:
	std::vector<c_base*> children;
	c_window(std::string, Vector2D sizes, bool draw, Vector2D pos);
	void add_control(c_base* control);
	virtual void draw() override;
};

class c_group : public c_base
{
public:
	std::vector<c_base*> children;
	c_group(std::string, Vector2D sizes, bool draw, Vector2D pos);
	void add_control(c_base* control);
	virtual void draw() override;
};




class c_menu
{
private:
public:
	auto draw() -> void;
};

extern c_menu g_menu;