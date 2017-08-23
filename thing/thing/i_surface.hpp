#pragma once
#include "window_includes.hpp"
#include "vector.hpp"
#include "utilities.hpp"
#include "color.hpp"

typedef ULONG HFont;

class c_surface
{
public:
	void draw_set_color(Color col)
	{
		typedef void(__thiscall *OrigFn)(void*, Color);
		g_utils.get_virtual_func<OrigFn>(this, 14)(this, col);
	}

	void draw_filled_rect(int x0, int y0, int x1, int y1) {
		typedef void(__thiscall *OrigFn)(void*, int, int, int, int);
		g_utils.get_virtual_func<OrigFn>(this, 16)(this, x0, y0, x1, y1);
	}

	void draw_outlined_rect(int x0, int y0, int x1, int y1) {
		typedef void(__thiscall *OrigFn)(void*, int, int, int, int);
		g_utils.get_virtual_func<OrigFn>(this, 18)(this, x0, y0, x1, y1);
	}
	void get_cursor_pos(int& x, int& y)
	{
		typedef void(__thiscall *OrigFn)(PVOID, int&, int&);
		g_utils.get_virtual_func<OrigFn>(this, 100)(this, x, y);
	}
	void draw_line(int x0, int y0, int x1, int y1) {
		typedef void(__thiscall *OrigFn)(void*, int, int, int, int);
		g_utils.get_virtual_func<OrigFn>(this, 19)(this, x0, y0, x1, y1);
	}
	void draw_outlined_circle(int x, int y, int radius, int segments)
	{
		typedef void(__thiscall *OrigFn)(PVOID, int, int, int, int);
		g_utils.get_virtual_func<OrigFn>(this, 103)(this, x, y, radius, segments);
	}
	void draw_set_font(HFont font) {
		typedef void(__thiscall *OrigFn)(void*, HFont);
		g_utils.get_virtual_func<OrigFn>(this, 23)(this, font);
	}

	void draw_set_text_color(Color col) {
		typedef void(__thiscall *OrigFn)(void*, Color);
		g_utils.get_virtual_func<OrigFn>(this, 24)(this, col);
	}

	void draw_set_text_pos(int x, int y) {
		typedef void(__thiscall *OrigFn)(void*, int, int);
		g_utils.get_virtual_func<OrigFn>(this, 26)(this, x, y);
	}

	void draw_print_text(const wchar_t *text, int textLen, FontDrawType drawType = FontDrawType::FONT_DRAW_DEFAULT) {
		typedef void(__thiscall *OrigFn)(void*, const wchar_t *, int, FontDrawType);
		g_utils.get_virtual_func<OrigFn>(this, 28)(this, text, textLen, drawType);
	}
	void draw_unicode_string(const wchar_t *pwString, FontDrawType drawType = FontDrawType::FONT_DRAW_DEFAULT)
	{
		typedef void(__thiscall *OrigFn)(void*, const wchar_t *, FontDrawType);
		g_utils.get_virtual_func<OrigFn>(this, 132)(this, pwString, drawType);
	}
	HFont create_font() {
		typedef HFont(__thiscall *OrigFn)(void*);
		return g_utils.get_virtual_func<OrigFn>(this, 71)(this);
	}

	bool set_font_glyph(HFont font, const char *windowsFontName, int tall, int weight, int blur, int scanlines, int flags, int nRangeMin = 0, int nRangeMax = 0) {
		typedef bool(__thiscall *OrigFn)(void*, HFont, const char*, int, int, int, int, int, int, int);
		return g_utils.get_virtual_func<OrigFn>(this, 72)(this, font, windowsFontName, tall, weight, blur, scanlines, flags, nRangeMin, nRangeMax);
	}

	void get_text_size(HFont font, const wchar_t *text, int &wide, int &tall) {
		typedef void(__thiscall *OrigFn)(void*, HFont, const wchar_t *, int&, int&);
		g_utils.get_virtual_func<OrigFn>(this, 79)(this, font, text, wide, tall);
	}
};