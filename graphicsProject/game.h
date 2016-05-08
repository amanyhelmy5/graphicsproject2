#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Renderer/Renderer.h"
#include "Model/my_hero.h"
#include"Collision/Collision_Manager.h"
#include "Model/square.h"
#include "actions.h"

class ApplicationManager;

class Game
{
	Renderer* m_renderer;
	Collision_Manager * m_collisionmanager;

	std::shared_ptr<my_hero> test_square;
    std::shared_ptr<Square> ground_plane;
    std::shared_ptr<Square> top_plane;
    std::shared_ptr<Square> right_plane;
    std::shared_ptr<Square> left_plane;
    std::shared_ptr<Square> front_plane;
    std::shared_ptr<Square> back_plane;

	float x = 0.0f;
    float angle = 0.0f;

	std::shared_ptr<Model> plane;
public:
	Game(Renderer* renderer, Collision_Manager *collision_manager);
    void initialize();

    void update(float delta, Actions p_actions);
};

#endif // GAME_H
