#pragma once
#include "window_includes.hpp"
#include "vector.hpp"
#include "utilities.hpp"
#include "color.hpp"

class c_debugoverlay
{
public:
	int ScreenPoint(const Vector& vecOrigin, Vector& vecScreen)
	{
		virtual_fn(int)(PVOID, const Vector&, Vector&);
		return g_utils.get_virtual_func< OriginalFn >(this, 13)(this, vecOrigin, vecScreen);
	}
	void AddSweptBoxOverlay(const Vector& start, const Vector& end, const Vector& mins, const Vector& max, const QAngle & angles, int r, int g, int b, int a, float flDuration)
	{
		virtual_fn(void)(PVOID, const Vector&, const Vector&, const Vector&, const Vector&, const QAngle&, int, int, int, int, float);
		g_utils.get_virtual_func< OriginalFn >(this, 9)(this, start, end, mins, max, angles, r, g, b, a, flDuration);
	}
	void AddBoxOverlay2(const Vector& origin, const Vector& mins, const Vector& max, QAngle const& orientation, const Color& faceColor, const Color& edgeColor, float duration)
	{
		virtual_fn(void)(PVOID, const Vector&, const Vector&, const Vector&, QAngle const&, const Color&, const Color&, float);
		g_utils.get_virtual_func< OriginalFn >(this, 21)(this, origin, mins, max, orientation, faceColor, edgeColor, duration);
	}
	void AddLineOverlay(const Vector& origin, const Vector& dest, int r, int g, int b, int a, bool noDepthTest, float flDuration)
	{
		virtual_fn(void)(PVOID, const Vector&, const Vector&, int, int, int, int, bool, float);
		g_utils.get_virtual_func<OriginalFn>(this, 4)(this, origin, dest, r, g, b, a, noDepthTest, flDuration);
	}
};