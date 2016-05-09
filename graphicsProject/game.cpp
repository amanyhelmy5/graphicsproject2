#include "game.h"


Game::~Game()
{
    m_renderer->empty_models();
}

Game::Game(Renderer * renderer, Collision_Manager * collision_manager)
{
	m_renderer = renderer;
	m_collision_manager = collision_manager;
}

void Game::initialize()
{
}

void Game::update(float delta, Actions p_actions)
{
	
}
