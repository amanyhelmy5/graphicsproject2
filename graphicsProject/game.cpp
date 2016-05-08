#include "game.h"



Game::Game(Renderer * renderer, Collision_Manager * collision_manager)
{
	m_renderer = renderer;
	m_collision_manager = collision_manager;
}


void Game::initialize()
{
	spider = std::shared_ptr<my_hero>(new my_hero("Spider/spider.obj", "Spider/SpiderTex.jpg"));
	spider2 = std::shared_ptr<my_hero>(new my_hero("Spider/spider.obj", "Spider/SpiderTex.jpg"));
    skybox		 =   std::shared_ptr<my_hero>  (new my_hero("skybox/skybox.obj", "skybox/skybox.png"));

    spider ->set_translation(0.0f, 0.0f, 0.0f);
	spider2->set_translation(0.0f, 250.0f, 0.0f);

    skybox->set_scale(150.0f, 150.0f, 150.0f);

    m_renderer->add_model(spider);
	m_renderer->add_model(spider2);
    m_renderer->add_model(skybox);

	m_collision_manager->AddCollidableModel((Collidable_Model*)spider.get());
	m_collision_manager->AddCollidableModel((Collidable_Model*)spider2.get());
}

void Game::update(float delta, Actions p_actions)
{
	if (p_actions.forwards)
    {
		spider->rotate(10.0f, 1.0f, 0.0f, 0.0f);
		spider->move(0.0f, 1.0f, 0.0f);
    }
}

