#include "Level2.h"


Level2::Level2(Renderer* renderer, Collision_Manager* collision_manager) : Game(renderer, collision_manager)
{
}

Level2::~Level2()
{
}

void Level2::initialize()
{
    dead_body = std::shared_ptr<Collidable_Model>(new Collidable_Model("Level1/cutbody.obj", "Level1/cutbody.png"));
    skybox = std::shared_ptr<Collidable_Model>(new Collidable_Model("Level1/skybox.obj", "Level1/skybox2.png"));
    //dead_body->set_scale(0.1f, 0.1f, 0.1f);
    skybox->set_scale(100.0f, 100.0f, 100.0f);
    m_renderer->add_model(dead_body);
	m_renderer->add_model(skybox);

}

void Level2::update(float delta, Actions p_actions)
{
	if (p_actions.forwards)
	{
        dead_body->rotate(90.0f, 0.0f, 1.0f, 0.0f);
	}
}
