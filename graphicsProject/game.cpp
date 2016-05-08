#include "game.h"


Game::Game(Renderer * renderer, Collision_Manager * collision_manager)
{
	m_renderer = renderer;
	m_collisionmanager = collision_manager;
}


void Game::initialize()
{
    test_square  =   std::shared_ptr<my_hero> (new my_hero("uvtemplate.bmp"));
    spider		 =   std::shared_ptr<Model>  (new Model("Spider/spider.obj", "Spider/SpiderTex.jpg"));
    skybox		 =   std::shared_ptr<Model>  (new Model("skybox/skybox.obj", "skybox/skybox.png"));

    test_square ->set_scale(0.25f, 0.25f, 0.25f);
    test_square ->set_translation(0.0f, 0.0f, 0.0f);

    spider->set_scale(0.1f, 0.1f, 0.1f);
    skybox->set_scale(5.0f, 5.0f, 5.0f);
	

	m_collisionmanager->AddCollidableModel((Collidable_Model*)test_square.get());

    m_renderer->add_model(test_square );
    m_renderer->add_model(spider);
    m_renderer->add_model(skybox);
}

void Game::update(float delta, Actions p_actions)
{
	if (p_actions.forwards)
    {
		test_square->move(0.0f, 0.2f, 0.0f);
        spider->rotate(10.0f, 1.0f, 0.0f, 0.0f);
    }
    angle += 1.1f;
}

