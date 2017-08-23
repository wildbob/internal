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
	b_box box;
	Vector m_vecFoot = entity->get_origin();
	Vector m_vecHead;

	if (entity->get_flags() & FL_DUCKING)
		m_vecHead = m_vecFoot + Vector(0.f, 0.f, 52.f);
	else
		m_vecHead = m_vecFoot + Vector(0.f, 0.f, 72.f);

	Vector m_vecFootScreen, m_vecHeadScreen;

	if (g_drawings.world_to_screen(m_vecFoot, m_vecFootScreen) && g_drawings.world_to_screen(m_vecHead, m_vecHeadScreen))
	{
		box.h = int(m_vecFootScreen.y - m_vecHeadScreen.y);
		box.w = int(box.h / 2);
		box.x = int(m_vecHeadScreen.x - box.w / 2);
		box.y = int(m_vecHeadScreen.y);
	}

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