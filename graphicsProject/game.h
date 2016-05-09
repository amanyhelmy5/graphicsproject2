#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Renderer/Renderer.h"
#include "Model/my_hero.h"
#include "Collision/Collision_Manager.h"
#include "Collision/Collidable_Model.h"

class ApplicationManager;
#include "Model/square.h"

#include "actions.h"

class Game
{
protected:
	Renderer* m_renderer;
	Collision_Manager* m_collision_manager;
    std::shared_ptr<Model> skybox;

public:
    Game(Renderer* renderer, Collision_Manager* collision_manager);
    virtual ~Game();
    virtual void initialize();
    virtual void update(float delta, Actions p_actions);
};

#endif // GAME_H
