#pragma once
#include "entity.hpp"
#include "instance.hpp"

class c_drawings
{
private:
public:
	c_drawings();
	~c_drawings();
	auto screen_transform(const  Vector &point, Vector &screen) -> bool;
	auto world_to_screen(Vector &origin, Vector &screen) -> bool;
	 HFont font1;
	 void setup_fonts();
	 void draw_string(HFont font, int x, int y, Color color, DWORD alignment, const char* msg, ...);
	 void draw_string_unicode(HFont font, int x, int y, Color color, bool bCenter, const wchar_t* msg, ...);
	 void draw_rect(int x, int y, int w, int h, Color col);
	 void draw_rainbow_rect(int x, int y, int w, int h, float flSpeed, float &flRainbow);
	 void draw_gradient_vertical(int x, int y, int w, int h, Color color1, Color color2);
	 void draw_gradient_horizontal(int x, int y, int w, int h, Color color1, Color color2);
	 void draw_pixel(int x, int y, Color col);
	 void draw_outlined_rect(int x, int y, int w, int h, Color col);
	 void draw_outlined_circle(int x, int y, int r, Color col);
	 void draw_line(int x0, int y0, int x1, int y1, Color col);
	 void draw_corner(int iX, int iY, int iWidth, int iHeight, bool bRight, bool bDown, Color colDraw);
	 void draw_rounded_box(int x, int y, int w, int h, int r, int v, Color col);
	 int  get_string_width(HFont font, const char* msg, ...);
	 void draw_3d_box(Vector* boxvectors, Color color);
	 void draw_circle(float x, float y, float r, float s, Color color);
};

extern c_drawings g_drawings;