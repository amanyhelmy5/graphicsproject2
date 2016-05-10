#include"Level1.h"

Level1::Level1(Renderer* renderer, Collision_Manager* collision_manager, EulerCamera* camera) : Game(renderer, collision_manager, camera)
{
}

Level1::~Level1()
{
}

void Level1::initialize()
{
    spider = std::shared_ptr<Collidable_Model>(new Collidable_Model("Spider/spider.obj", "Spider/SpiderTex.jpg"));
    spider2 = std::shared_ptr<Collidable_Model>(new Collidable_Model("Spider/spider.obj", "Spider/SpiderTex.jpg"));
    skybox = std::shared_ptr<Collidable_Model>(new Collidable_Model("skybox/skybox.obj", "skybox/skybox.png"));
	spider->set_scale(0.1f, 0.1f, 0.1f);
    spider2->set_scale(0.1f, 0.1f, 0.1f);
    spider->move(0.0f, 0.0f, -50.0f);
    spider2->move(0.0f, 10.0f, -50.0f);
    skybox->set_scale(100.0f, 100.0f, 100.0f);
	m_renderer->add_model(spider);
    m_renderer->add_model(spider2);
	m_renderer->add_model(skybox);
    m_collision_manager->AddCollidableModel((Collidable*)spider.get());
    m_collision_manager->AddCollidableModel((Collidable*)spider2.get());
}

 void Level1::update(float delta, Actions actions)
{
    Game::update(delta, actions);
    if (actions.forwards)
	{
        spider->rotate(40.0f, 1.0f, 0.0f, 0.0f);
        spider->move(0.0f, 0.3f, 0.0f);
	}
}
