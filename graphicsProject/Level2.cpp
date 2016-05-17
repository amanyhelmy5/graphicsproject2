#include "Level2.h"


Level2::Level2(Renderer* renderer, Collision_Manager* collision_manager, EulerCamera* camera) : Game(renderer, collision_manager, camera)
{
}

Level2::~Level2()
{
}

void Level2::initialize()
{
	//dead_body = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/eaurupsoldier.obj", "firstlevel/africansoldier.png"));
    skybox = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/skybox.obj", "secondlevel/space.png"));
	enimy1 = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/enimy1.obj", "secondlevel/enimy1.png"));
	enimy2 = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/enimy2.obj", "secondlevel/enimy2.png"));
	enimy3 = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/enimy3.obj", "secondlevel/enimy1.png"));
	enimy4 = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/enimy4.obj", "secondlevel/enimy2.png"));
	enimy5 = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/enimy5.obj", "secondlevel/enimy1.png"));
	enimy6 = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/enimy6.obj", "secondlevel/enimy2.png"));
	enimy7 = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/enimy7.obj", "secondlevel/enimy2.png"));

  //  dead_body->set_scale(300.10f, 300.10f, 300.10f);
    skybox->set_scale(80.0f, 80.0f, 80.0f);
  //  m_renderer->add_model(dead_body);
	m_renderer->add_model(skybox);
	m_renderer->add_model(enimy1);
	m_renderer->add_model(enimy2);
	m_renderer->add_model(enimy3);
	m_renderer->add_model(enimy4);
	m_renderer->add_model(enimy5);
	m_renderer->add_model(enimy6);
	m_renderer->add_model(enimy7);
	//m_collision_manager->AddCollidableModel((Collidable*)dead_body.get());
	//m_collision_manager->AddCollidableModel((Collidable*)skybox.get());

}

void Level2::update(float delta, Actions actions)
{
    Game::update(delta, actions);

    if (actions.forwards)
	{
//        dead_body->rotate(90.0f, 0.0f, 1.0f, 0.0f);
	}
}
