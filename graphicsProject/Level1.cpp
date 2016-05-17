#include"Level1.h"

Level1::Level1(Renderer* renderer, Collision_Manager* collision_manager, EulerCamera* camera) : Game(renderer, collision_manager, camera)
{
}

Level1::~Level1()
{
}

void Level1::initialize()
{
    house = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/skybox.obj", "firstlevel/house.png"));
	wall1 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/wall1.obj", "firstlevel/wall1.png"));
	wall2 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/wall2.obj", "firstlevel/wall2.png"));
	wall3 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/wall3.obj", "firstlevel/wall2.png"));

	enimy1 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy1.obj", "firstlevel/SpiderTex.jpg"));
	enimy2 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy2.obj", "firstlevel/SpiderTex.jpg"));
	enimy3 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy3.obj", "firstlevel/SpiderTex.jpg"));
	enimy4 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy4.obj", "firstlevel/SpiderTex.jpg"));
	enimy5 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy5.obj", "firstlevel/SpiderTex.jpg"));
	enimy6 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy6.obj", "firstlevel/SpiderTex.jpg"));
	enimy7 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy7.obj", "firstlevel/SpiderTex.jpg"));
	enimy8 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy8.obj", "firstlevel/SpiderTex.jpg"));
	enimy9 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy9.obj", "firstlevel/SpiderTex.jpg"));
	house->set_scale(15.f, 15.f, 15.f);

	wall1->set_scale(60.f, 70.f, 90.f);
	wall2->set_scale(20.f, 20.f, 20.f);
	wall3->set_scale(99.f, 100.f, 99.f);
	enimy1->set_scale(3.f, 3.f, 3.f);
	enimy2->set_scale(3.f, 3.f, 3.f);

	enimy3->set_scale(3.f, 3.f, 3.f);
	enimy4->set_scale(3.f, 3.f, 3.f);
	enimy5->set_scale(3.f, 3.f, 3.f);
	enimy6->set_scale(3.f, 3.f, 3.f);
	enimy7->set_scale(3.f, 3.f, 3.f);
	enimy8->set_scale(3.f, 3.f, 3.f);
	enimy9->set_scale(3.f, 3.f, 3.f);

	m_renderer->add_model(wall1);
    m_renderer->add_model(wall2);
	m_renderer->add_model(wall3);
	m_renderer->add_model(house);
	m_renderer->add_model(enimy1);
	m_renderer->add_model(enimy2);
	m_renderer->add_model(enimy3);
	m_renderer->add_model(enimy4);
	m_renderer->add_model(enimy5);
	m_renderer->add_model(enimy6);
	m_renderer->add_model(enimy7);
	m_renderer->add_model(enimy8);
	m_renderer->add_model(enimy9);

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
