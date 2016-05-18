#include "Level2.h"


Level2::Level2(Renderer* renderer, Collision_Manager* collision_manager, EulerCamera* camera, Sound* sound) : Game(renderer, collision_manager, camera, sound)
{
}

Level2::~Level2()
{
}

void Level2::initialize()
{
	//dead_body = std::shared_ptr<Collidable_Model>(new Collidable_Model("firstlevel/eaurupsoldier.obj", "firstlevel/africansoldier.png"));
    skybox = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/skybox.obj", "secondlevel/space.png", ana_meen::WALL));
    enemy1 = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/enimy1.obj", "secondlevel/enimy1.png", ana_meen::ENEMY));
    enemy2 = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/enimy2.obj", "secondlevel/enimy2.png", ana_meen::ENEMY));
    enemy3 = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/enimy3.obj", "secondlevel/enimy1.png", ana_meen::ENEMY));
    enemy4 = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/enimy4.obj", "secondlevel/enimy2.png", ana_meen::ENEMY));
    enemy5 = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/enimy5.obj", "secondlevel/enimy1.png", ana_meen::ENEMY));
    enemy6 = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/enimy6.obj", "secondlevel/enimy2.png", ana_meen::ENEMY));
    enemy7 = std::shared_ptr<Collidable_Model>(new Collidable_Model("secondlevel/enimy7.obj", "secondlevel/enimy2.png", ana_meen::ENEMY));

  //  dead_body->set_scale(300.10f, 300.10f, 300.10f);
    skybox->set_scale(80.0f, 80.0f, 80.0f);
  //  m_renderer->add_model(dead_body);
	m_renderer->add_model(skybox);
    m_renderer->add_model(enemy1);
    m_renderer->add_model(enemy2);
    m_renderer->add_model(enemy3);
    m_renderer->add_model(enemy4);
    m_renderer->add_model(enemy5);
    m_renderer->add_model(enemy6);
    m_renderer->add_model(enemy7);
	//m_collision_manager->AddCollidableModel((Collidable*)dead_body.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy1.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy2.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy3.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy4.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy5.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy6.get());
    m_collision_manager->AddCollidableModel((Collidable*)enemy7.get());

}

void Level2::update(float delta, Actions actions)
{
    Game::update(delta, actions);

    if (actions.forwards)
	{
//        dead_body->rotate(90.0f, 0.0f, 1.0f, 0.0f);
	}
}
