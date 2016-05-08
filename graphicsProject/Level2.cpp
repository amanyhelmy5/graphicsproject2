#include "Level2.h"


Level2::Level2(Renderer* renderer) : Game(renderer)
{
}

Level2::~Level2()
{
}

void Game::initialize()
{
	//plane		 =   std::shared_ptr<Model>  (new Model("poss/grass.png", "poss/grass.obj"));
	//body = std::shared_ptr<Model>(new Model("spider/torch2.png", "spider/torch2."));
	test_square = std::shared_ptr<Square>(new Square("uvtemplate.bmp"));
	spider = std::shared_ptr<Model>(new Model("Level1/cutbody.obj", "Level1/cutbody.png"));
	skybox = std::shared_ptr<Model>(new Model("Level1/skybox.obj", "Level1/skybox2.png"));
	test_square->set_scale(0.25f, 0.25f, 0.25f);
	test_square->set_translation(0.0f, 0.0f, 0.0f);
	spider->set_scale(0.1f, 0.1f, 0.1f);
	skybox->set_scale(5.0f, 5.0f, 5.0f);
	m_renderer->add_model(test_square);
	m_renderer->add_model(spider);
	m_renderer->add_model(skybox);

}

void Game::update(float delta, Actions p_actions)
{
	if (p_actions.forwards)
	{
		test_square->move(0.0f, 0.2, 0.0f);
		spider->rotate(90.0f, 0.0f, 1.0f, 0.0f);
	}
	angle += 1.1f;
}