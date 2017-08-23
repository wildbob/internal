#pragma once
#include "menu.hpp"
#include "drawings.hpp"

c_menu g_menu;

//made this while learning inheritence please don't judge



c_window::c_window(std::string title, Vector2D sizes, bool draw, Vector2D pos)
{
	this->name = title;
	this->size = sizes;
	this->should_draw = draw;
	this->position = pos;
	this->draw();
}

auto c_window::add_control(c_base* control) -> void
{
	children.push_back(control);
	parent->set_parent(this);
}

auto c_window::draw() -> void
{
	if (!this->should_draw)
		return;

	for (auto i = 0; i < children.size(); i++)
		children[i]->set_position(Vector2D(16, 16 * i));

	g_drawings.draw_rect(position.x, position.y, size.x, size.y, Color(0, 0, 0, 255));

	for (auto i = 0; i < children.size(); i++)
		children[i]->draw();
}

c_group::c_group(std::string title, Vector2D sizes, bool draw, Vector2D pos)
{
	this->name = title;
	this->size = sizes;
	this->should_draw = draw;
	this->position = pos;
	this->draw();
}

auto c_group::add_control(c_base* control) -> void
{
	children.push_back(control);
	parent->set_parent(this);
}

auto c_group::draw() -> void
{
	if (!this->should_draw)
		return;

	for (auto i = 0; i < children.size(); i++)
		children[i]->set_position(Vector2D(16, 16 * i));

	g_drawings.draw_outlined_rect(position.x, position.y, size.x, size.y, Color(250, 0, 0, 255));

	for (auto i = 0; i < children.size(); i++)
		children[i]->draw();
}

auto c_menu::draw() -> void
{
	c_window* window = new c_window("fat guy", Vector2D(300, 300), true, Vector2D(450, 450));
	c_group* group = new c_group("deez nutz", Vector2D(150,150), true, Vector2D(500,500));
}

