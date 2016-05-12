#include"Level1.h"

Level1::Level1(Renderer* renderer, Collision_Manager* collision_manager, EulerCamera* camera) : Game(renderer, collision_manager, camera)
{
}

Level1::~Level1()
{
}

void Level1::initialize()
{
    house = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/house.obj", "firstlevel/house.png"));
	wall1 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/wall1.obj", "firstlevel/wall1.png"));
	wall2 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/wall2.obj", "firstlevel/wall2.png"));
	wall3 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/wall3.obj", "firstlevel/wall2.png"));

	house->set_scale(100.f, 100.f, 100.f);
	wall1->set_scale(60.f, 70.f, 90.f);
	wall2->set_scale(99.f, 99.f, 99.f);
	wall3->set_scale(99.f, 100.f, 99.f);

	m_renderer->add_model(wall1);
    m_renderer->add_model(wall2);
	m_renderer->add_model(wall3);
	m_renderer->add_model(house);

    m_collision_manager->AddCollidableModel((Collidable*)wall1.get());
    m_collision_manager->AddCollidableModel((Collidable*)wall2.get());
	m_collision_manager->AddCollidableModel((Collidable*)wall3.get());
	m_collision_manager->AddCollidableModel((Collidable*)house.get());
}

 void Level1::update(float delta, Actions actions)
{
    Game::update(delta, actions);
  /*  if (actions.forwards)
	{
        spider->rotate(40.0f, 1.0f, 0.0f, 0.0f);
        spider->move(0.0f, 0.3f, 0.0f);
	}*/
}
