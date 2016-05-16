#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Renderer/Renderer.h"
#include "Model/Collidable_Model.h"
#include "Collision/Collision_Manager.h"
#include "Collision/Collidable.h"

class ApplicationManager;
#include "Model/square.h"

#include "actions.h"

class Game
{
    struct Vec3
    {
        float x;
        float y;
        float z;
    };

    const float m_speed_limit = 20.0f;
    Vec3 m_current_speed;
    const float m_acceleration_rate = 0.7f;

    void round_speed();
protected:

	Renderer* m_renderer;
	Collision_Manager* m_collision_manager;
    std::shared_ptr<Model> skybox;
    EulerCamera* m_camera;

public:
    Game(Renderer* renderer, Collision_Manager* collision_manager, EulerCamera* m_camera);
    virtual ~Game();
    virtual void initialize();
    virtual void update(float delta, Actions actions);
};

#endif // GAME_H
