#include"Level1.h"

Level1::Level1(Renderer* renderer, Collision_Manager* collision_manager, EulerCamera* camera, Sound* sound) : Game(renderer, collision_manager, camera, sound)
{
}

Level1::~Level1()
{
}

void Level1::initialize()
{
    house = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/skybox.obj", "firstlevel/house.png", ana_meen::WALL));
    wall1 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/wall1.obj", "firstlevel/wall1.png", ana_meen::WALL));
    wall2 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/wall2.obj", "firstlevel/wall2.png", ana_meen::WALL));
    wall3 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/wall3.obj", "firstlevel/wall2.png", ana_meen::WALL));

    enemy1 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy1.obj", "firstlevel/SpiderTex.jpg", ana_meen::ENEMY));
    enemy2 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy2.obj", "firstlevel/SpiderTex.jpg", ana_meen::ENEMY));
    enemy3 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy3.obj", "firstlevel/SpiderTex.jpg", ana_meen::ENEMY));
    enemy4 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy4.obj", "firstlevel/SpiderTex.jpg", ana_meen::ENEMY));
    enemy5 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy5.obj", "firstlevel/SpiderTex.jpg", ana_meen::ENEMY));
    enemy6 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy6.obj", "firstlevel/SpiderTex.jpg", ana_meen::ENEMY));
    enemy7 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy7.obj", "firstlevel/SpiderTex.jpg", ana_meen::ENEMY));
    enemy8 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy8.obj", "firstlevel/SpiderTex.jpg", ana_meen::ENEMY));
    enemy9 = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/senimy9.obj", "firstlevel/SpiderTex.jpg", ana_meen::ENEMY));

    house->set_scale(15.f, 15.f, 15.f);
    wall1->set_scale(60.f, 70.f, 90.f);
    wall2->set_scale(20.f, 20.f, 20.f);
    wall3->set_scale(99.f, 100.f, 99.f);
    enemy1->set_scale(3.f, 3.f, 3.f);
    enemy2->set_scale(3.f, 3.f, 3.f);
    enemy3->set_scale(3.f, 3.f, 3.f);
    enemy4->set_scale(3.f, 3.f, 3.f);
    enemy5->set_scale(3.f, 3.f, 3.f);
    enemy6->set_scale(3.f, 3.f, 3.f);
    enemy7->set_scale(3.f, 3.f, 3.f);
    enemy8->set_scale(3.f, 3.f, 3.f);
    enemy9->set_scale(3.f, 3.f, 3.f);

	m_renderer->add_model(wall1);
    m_renderer->add_model(wall2);
	m_renderer->add_model(wall3);

	m_renderer->add_model(house);
    m_renderer->add_model(enemy1);
    m_renderer->add_model(enemy2);
    m_renderer->add_model(enemy3);
    m_renderer->add_model(enemy4);
    m_renderer->add_model(enemy5);
    m_renderer->add_model(enemy6);
    m_renderer->add_model(enemy7);
    m_renderer->add_model(enemy8);
    m_renderer->add_model(enemy9);


    m_collision_manager->AddCollidableModel((Collidable*)wall1.get());
    m_collision_manager->AddCollidableModel((Collidable*)wall2.get());
	m_collision_manager->AddCollidableModel((Collidable*)wall3.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy1.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy2.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy3.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy4.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy5.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy6.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy7.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy8.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy9.get());
    //m_collision_manager->AddCollidableModel((Collidable*)house.get());
}

 void Level1::update(float delta, Actions actions)
{
    Game::update(delta, actions);
}
