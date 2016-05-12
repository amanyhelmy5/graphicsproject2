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

    m_current_speed.x = 0.0f;
    m_current_speed.y = 0.0f;
    m_current_speed.z = 0.0f;
}

void Game::initialize()
{
}

void Game::update(float delta, Actions actions)
{
    if (actions.forwards && m_current_speed.x < m_speed_limit)
        m_current_speed.x += m_acceleration_rate;
    if (actions.backwards && m_current_speed.x > -m_speed_limit)
        m_current_speed.x -= m_acceleration_rate;
    if (!actions.forwards && m_current_speed.x > 0)
        m_current_speed.x -= m_acceleration_rate;
    if (!actions.backwards && m_current_speed.x < 0)
        m_current_speed.x += m_acceleration_rate;

    if (actions.right && m_current_speed.y < m_speed_limit)
        m_current_speed.y += m_acceleration_rate;
    if (actions.left && m_current_speed.y > -m_speed_limit)
        m_current_speed.y -= m_acceleration_rate;
    if (!actions.right && m_current_speed.y > 0)
        m_current_speed.y -= m_acceleration_rate;
    if (!actions.left && m_current_speed.y < 0)
        m_current_speed.y += m_acceleration_rate;

    if (actions.jump && m_current_speed.z < m_speed_limit)
        m_current_speed.z += m_acceleration_rate;
    if (actions.fall && m_current_speed.z > -m_speed_limit)
        m_current_speed.z -= m_acceleration_rate;
    if (!actions.jump && m_current_speed.z > 0)
        m_current_speed.z -= m_acceleration_rate;
    if (!actions.fall && m_current_speed.z < 0)
        m_current_speed.z += m_acceleration_rate;

    round_speed();

    m_camera->walk  (m_current_speed.x);
    m_camera->strafe(m_current_speed.y);
    m_camera->fly   (m_current_speed.z);
}


void Game::round_speed()
{
    float rounding_const = 0.7f;
    if (m_current_speed.x > -rounding_const && m_current_speed.x < rounding_const)
        m_current_speed.x = 0.0f;
    if (m_current_speed.x <  rounding_const && m_current_speed.x > rounding_const)
        m_current_speed.x = 0.0f;
    if (m_current_speed.y > -rounding_const && m_current_speed.y < rounding_const)
        m_current_speed.y = 0.0f;
    if (m_current_speed.y <  rounding_const && m_current_speed.y > rounding_const)
        m_current_speed.y = 0.0f;
    if (m_current_speed.z > -rounding_const && m_current_speed.z < rounding_const)
        m_current_speed.z = 0.0f;
    if (m_current_speed.z <  rounding_const && m_current_speed.z > rounding_const)
        m_current_speed.z = 0.0f;
}
