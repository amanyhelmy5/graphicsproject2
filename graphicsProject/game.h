#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Renderer/Renderer.h"
#include "Model/my_hero.h"
#include"Collision/Collision_Manager.h"

class ApplicationManager;
#include "Model/square.h"
#include "actions.h"

class Game
{
	Renderer* m_renderer;
	Collision_Manager * m_collisionmanager;

	std::shared_ptr<my_hero> test_square;

	float x = 0.0f;
    

    float angle = 0.0f;

    std::shared_ptr<Model> spider;
    std::shared_ptr<Model> skybox;
	std::shared_ptr<Model> plane;

public:
	Game(Renderer* renderer, Collision_Manager *collision_manager);
    void initialize();

   
    void update(float delta, Actions p_actions);
};

#endif // GAME_H
