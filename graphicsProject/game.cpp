#include "game.h"


Game::~Game()
{
    m_renderer->empty_models();
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
    if (actions.forwards)
        m_camera->walk(1);

    if (actions.backwards)
        m_camera->walk(-1);

    if (actions.right)
        m_camera->strafe(1);

    if (actions.left)
        m_camera->strafe(-1);

    if (actions.jump)
        m_camera->fly(1);

    if (actions.fall)
        m_camera->fly(-1);
}
