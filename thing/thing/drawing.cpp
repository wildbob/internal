#pragma once
#include "drawings.hpp"
c_drawings g_drawings;

static bool font = false;

c_drawings::c_drawings()
{

}

c_drawings::~c_drawings()
{

}

auto c_drawings::world_to_screen(Vector &origin, Vector &screen) -> bool
{
	if (screen_transform(origin, screen)) {
		int w, h;
		g_instance.m_engine()->get_screen_size(w, h);

		screen.x = (w / 2.0f) + (screen.x * w) / 2.0f;
		screen.y = (h / 2.0f) - (screen.y * h) / 2.0f;

		return true;
	}
	return false;
}

auto c_drawings::screen_transform(const  Vector &point, Vector &screen) -> bool
{
	static auto& w2sMatrix = g_instance.m_engine()->world_to_screen_matrix();

	screen.x = w2sMatrix.m[0][0] * point.x + w2sMatrix.m[0][1] * point.y + w2sMatrix.m[0][2] * point.z + w2sMatrix.m[0][3];
	screen.y = w2sMatrix.m[1][0] * point.x + w2sMatrix.m[1][1] * point.y + w2sMatrix.m[1][2] * point.z + w2sMatrix.m[1][3];
	screen.z = 0.0f;

	float w = w2sMatrix.m[3][0] * point.x + w2sMatrix.m[3][1] * point.y + w2sMatrix.m[3][2] * point.z + w2sMatrix.m[3][3];

	if (w < 0.001f) {
		screen.x *= 100000;
		screen.y *= 100000;
		return false;
	}

	screen.x /= w;
	screen.y /= w;

	return true;
}

void c_drawings::setup_fonts()
{
	if (!font)
	{
		g_instance.m_surface()->set_font_glyph(font1 = g_instance.m_surface()->create_font(), "Tahoma", 12, FW_DONTCARE, NULL, NULL, (int)FontFlags::FONTFLAG_ANTIALIAS | (int)FontFlags::FONTFLAG_OUTLINE);
		font = true;
	}
}

void c_drawings::draw_string(HFont font, int x, int y, Color color, DWORD alignment, const char* msg, ...)
{
	wchar_t formated[128] = { '\0' };
	wsprintfW(formated, L"%S", msg);
	int iWidth, iHeight;

	g_instance.m_surface()->get_text_size(font, formated, iWidth, iHeight);

	if (alignment & FONT_CENTER)
		x -= iWidth / 2;

	g_instance.m_surface()->draw_set_text_pos(x, y);
	g_instance.m_surface()->draw_set_text_color(color);
	g_instance.m_surface()->draw_set_font(font);
	g_instance.m_surface()->draw_print_text(formated, wcslen(formated));
}

void c_drawings::draw_string_unicode(HFont font, int x, int y, Color color, bool bCenter, const wchar_t* msg, ...)
{
	int r = 255, g = 255, b = 255, a = 255;
	color.GetColor(r, g, b, a);

	int iWidth, iHeight;

	g_instance.m_surface()->get_text_size(font, msg, iWidth, iHeight);
	g_instance.m_surface()->draw_set_font(font);
	g_instance.m_surface()->draw_set_text_color(Color(r, g, b, a));
	g_instance.m_surface()->draw_set_text_pos(!bCenter ? x : x - iWidth / 2, y - iHeight / 2);
	g_instance.m_surface()->draw_print_text(msg, wcslen(msg));
}

void c_drawings::draw_rect(int x, int y, int w, int h, Color col)
{
	g_instance.m_surface()->draw_set_color(col);
	g_instance.m_surface()->draw_filled_rect(x, y, x + w, y + h);
}

void c_drawings::draw_gradient_horizontal(int x, int y, int width, int height, Color color1, Color color2)
{
	float flDifferenceR = (float)(color2.r() - color1.r()) / (float)width;
	float flDifferenceG = (float)(color2.g() - color1.g()) / (float)width;
	float flDifferenceB = (float)(color2.b() - color1.b()) / (float)width;

	for (float i = 0.f; i < width; i++)
	{
		Color colGradient = Color(color1.r() + (flDifferenceR * i), color1.g() + (flDifferenceG * i), color1.b() + (flDifferenceB * i), color1.a());
		draw_rect(x + i, y, 1, height, colGradient);
	}
}

void c_drawings::draw_pixel(int x, int y, Color col)
{
	g_instance.m_surface()->draw_set_color(col);
	g_instance.m_surface()->draw_filled_rect(x, y, x + 1, y + 1);
}

void c_drawings::draw_outlined_rect(int x, int y, int w, int h, Color col)
{
	g_instance.m_surface()->draw_set_color(col);
	g_instance.m_surface()->draw_outlined_rect(x, y, x + w, y + h);
}

void c_drawings::draw_outlined_circle(int x, int y, int r, Color col)
{
	g_instance.m_surface()->draw_set_color(col);
	g_instance.m_surface()->draw_outlined_circle(x, y, r, 1);
}

void c_drawings::draw_line(int x0, int y0, int x1, int y1, Color col)
{
	g_instance.m_surface()->draw_set_color(col);
	g_instance.m_surface()->draw_line(x0, y0, x1, y1);
}


void c_drawings::draw_corner(int iX, int iY, int iWidth, int iHeight, bool bRight, bool bDown, Color colDraw)
{
	int iRealX = bRight ? iX - iWidth : iX;
	int iRealY = bDown ? iY - iHeight : iY;

	if (bDown && bRight)
		iWidth = iWidth + 1;

	draw_rect(iRealX, iY, iWidth, 1, colDraw);
	draw_rect(iX, iRealY, 1, iHeight, colDraw);

	draw_rect(iRealX, bDown ? iY + 1 : iY - 1, !bDown && bRight ? iWidth + 1 : iWidth, 1, Color(0, 0, 0, 255));
	draw_rect(bRight ? iX + 1 : iX - 1, bDown ? iRealY : iRealY - 1, 1, bDown ? iHeight + 2 : iHeight + 1, Color(0, 0, 0, 255));
}



int GetStringWidth(HFont font, const char* msg, ...)
{
	va_list va_alist;
	char buf[1024];
	va_start(va_alist, msg);
	_vsnprintf_s(buf, sizeof(buf), msg, va_alist);
	va_end(va_alist);
	wchar_t wbuf[1024];
	MultiByteToWideChar(CP_UTF8, 0, buf, 256, wbuf, 256);

	int iWidth, iHeight;

	g_instance.m_surface()->get_text_size(font, wbuf, iWidth, iHeight);

	return iWidth;
}


void c_drawings::draw_circle(float x, float y, float r, float s, Color color)
{
	float Step = M_PI * 2.0 / s;
	for (float a = 0; a < (M_PI*2.0); a += Step)
	{
		float x1 = r * cos(a) + x;
		float y1 = r * sin(a) + y;
		float x2 = r * cos(a + Step) + x;
		float y2 = r * sin(a + Step) + y;

		draw_line(x1, y1, x2, y2, color);
	}
}
