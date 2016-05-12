#include "game.h"


Game::~Game()
{
    m_renderer->empty_models();
    m_collision_manager->empty_collidable_models();
}

Game::Game(Renderer * renderer, Collision_Manager * collision_manager, EulerCamera* camera)
{
	m_renderer = renderer;
	m_collision_manager = collision_manager;
    m_camera = camera;
}

void Game::initialize()
{
}

void Game::update(float delta, Actions actions)
{
	float speed = 10.0f;
    if (actions.forwards)
        m_camera->walk(speed);

    if (actions.backwards)
		m_camera->walk(-speed);

    if (actions.right)
		m_camera->strafe(speed);

    if (actions.left)
		m_camera->strafe(-speed);

    if (actions.jump)
		m_camera->fly(speed);

    if (actions.fall)
		m_camera->fly(-speed);
}
