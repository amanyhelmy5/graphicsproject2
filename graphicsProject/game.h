#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Renderer/Renderer.h"
#include "Model/my_hero.h"
#include"Collision/Collision_Manager.h"
#include"graphicsProject\Collision\Collidable_Model.h"

class ApplicationManager;
#include "Model/square.h"
#include "actions.h"

class Game
{
	Renderer* m_renderer;
	Collision_Manager* m_collision_manager;
	std::shared_ptr<my_hero> spider2;
	std::shared_ptr<my_hero> spider;

	std::vector<Collidable_Model*> collidable_models;

	float x = 0.0f;
    

    float angle = 0.0f;

    std::shared_ptr<Model> skybox;
	std::shared_ptr<Model> plane;

public:
	Game(Renderer* renderer, Collision_Manager *collision_manager);
    void initialize();

   
    void update(float delta, Actions p_actions);
};

#endif // GAME_H
