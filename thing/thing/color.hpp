#pragma once
#include "window_includes.hpp"

class Color
{
public:
	// constructors
	Color()
	{
		*((int *)this) = 0;
	}
	Color(int r, int g, int b)
	{
		SetColor(r, g, b, 255);
	}
	Color(int r, int g, int b, int a)
	{
		SetColor(r, g, b, a);
	}
	void SetColor(int r, int g, int b, int a = 0)
	{
		_color[0] = (unsigned char)r;
		_color[1] = (unsigned char)g;
		_color[2] = (unsigned char)b;
		_color[3] = (unsigned char)a;
	}

	void GetColor(int &r, int &g, int &b, int &a) const
	{
		r = _color[0];
		g = _color[1];
		b = _color[2];
		a = _color[3];
	}

	void SetRawColor(int color32)
	{
		*((int *)this) = color32;
	}

	int GetRawColor() const
	{
		return *((int *)this);
	}

	inline int r() const { return _color[0]; }
	inline int g() const { return _color[1]; }
	inline int b() const { return _color[2]; }
	inline int a() const { return _color[3]; }

	void SetAlpha(int a) { _color[0] = (unsigned char)a; }
	int  GetAlpha() { return _color[0]; }


	unsigned char &operator[](int index)
	{
		return _color[index];
	}

	const unsigned char &operator[](int index) const
	{
		return _color[index];
	}

	bool operator == (const Color &rhs) const
	{
		return (*((int *)this) == *((int *)&rhs));
	}

	bool operator != (const Color &rhs) const
	{
		return !(operator==(rhs));
	}

	Color &operator=(const Color &rhs)
	{
		SetRawColor(rhs.GetRawColor());
		return *this;
	}

private:
	unsigned char _color[4];
};