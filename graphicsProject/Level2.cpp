#include "Level2.h"


Level2::Level2(Renderer* renderer, Collision_Manager* collision_manager, EulerCamera* camera) : Game(renderer, collision_manager, camera)
{
}

Level2::~Level2()
{
}

void Level2::initialize()
{
	dead_body = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/eaurupsoldier.obj", "firstlevel/africansoldier.png"));
    skybox = std::shared_ptr<Collidable_Model>(new Collidable_Model("skybox/skybox.obj", "skygbox/skybox.png"));
    dead_body->set_scale(300.10f, 300.10f, 300.10f);
    skybox->set_scale(100.0f, 100.0f, 100.0f);
    m_renderer->add_model(dead_body);
	m_renderer->add_model(skybox);
	m_collision_manager->AddCollidableModel((Collidable*)dead_body.get());
	m_collision_manager->AddCollidableModel((Collidable*)skybox.get());
}

void Level2::update(float delta, Actions actions)
{
    Game::update(delta, actions);

 /*   if (actions.forwards)
	{
        dead_body->rotate(90.0f, 0.0f, 1.0f, 0.0f);
	}*/
}
