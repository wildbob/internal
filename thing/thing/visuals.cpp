#include "visuals.hpp"
#include "math.hpp"
#include "drawings.hpp"



c_visuals::c_visuals()
{
	//constructor
}

c_visuals::~c_visuals()
{
	//destructor
}

auto c_visuals::get_box(c_entity* entity) -> b_box
{
		b_box box{};

	Vector flb, brt, blb, frt, frb, brb, blt, flt;

	Vector m_min = entity->get_min();
	Vector m_max = entity->get_max();
	const matrix3x4_t& trans = entity->get_coordinate_frame();

	Vector points[] = {
		Vector(m_min.x, m_min.y, m_min.z),
		Vector(m_min.x, m_max.y, m_min.z),
		Vector(m_max.x, m_max.y, m_min.z),
		Vector(m_max.x, m_min.y, m_min.z),
		Vector(m_max.x, m_max.y, m_max.z),
		Vector(m_min.x, m_max.y, m_max.z),
		Vector(m_min.x, m_min.y, m_max.z),
		Vector(m_max.x, m_min.y, m_max.z)
	};

	Vector pointsTransformed[8];
	for (int i = 0; i < 8; i++) {
		g_math.vector_transform_2(points[i], trans, pointsTransformed[i]);
	}


	if (!g_drawings.world_to_screen(pointsTransformed[3], flb) || !g_drawings.world_to_screen(pointsTransformed[5], brt)
		|| !g_drawings.world_to_screen(pointsTransformed[0], blb) || !g_drawings.world_to_screen(pointsTransformed[4], frt)
		|| !g_drawings.world_to_screen(pointsTransformed[2], frb) || !g_drawings.world_to_screen(pointsTransformed[1], brb)
		|| !g_drawings.world_to_screen(pointsTransformed[6], blt) || !g_drawings.world_to_screen(pointsTransformed[7], flt))
		return box;

	Vector arr[] = { flb, brt, blb, frt, frb, brb, blt, flt };

	// Init this shit
	auto left = flb.x;
	auto top = flb.y;
	auto right = flb.x;
	auto bottom = flb.y;

	// Find the bounding corners for our box
	for (int i = 1; i < 8; i++)
	{
		if (left > arr[i].x)
			left = arr[i].x;
		if (bottom < arr[i].y)
			bottom = arr[i].y;
		if (right < arr[i].x)
			right = arr[i].x;
		if (top > arr[i].y)
			top = arr[i].y;
	}

	box.x = left;
	box.y = top;
	box.w = right - left;
	box.h = bottom - top;

	return box;
}

auto c_visuals::boundingbox(c_entity* entity, b_box box) -> void
{
	g_drawings.draw_outlined_rect(box.x, box.y, box.w, box.h, Color(255,0,0,255));
}

auto c_visuals::healthbar(c_entity* entity, b_box box) -> void
{
	int health = entity->get_health();

	if (health > 100)
		health = 100;

	float h = (box.h);
	float offset = (h / 4.f) + 5;
	UINT hw = (UINT)(((box.w - 2) * health) / 100);

	g_drawings.draw_rect(box.x, box.y - 15, box.w, 5, Color(0, 0, 0, 170));
	g_drawings.draw_rect(box.x + 1, box.y - 14, hw, 3, Color(255,155,0,255));
}

auto c_visuals::run() -> void
{
	//iterate thru all active entites
	for (int i = 0; i < g_instance.m_entitylist( )->get_hightest_entity_index( ); i++)
	{
		auto target = static_cast< c_entity* >( g_instance.m_entitylist( )->get_entity( i ) );

		//checks
		if ( !target->is_valid_player( ) )
			continue;

		auto box = get_box( target );

		boundingbox( target, box );
		healthbar(target, box);
	}
}
