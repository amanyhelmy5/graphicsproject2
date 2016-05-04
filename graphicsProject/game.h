#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Renderer/Renderer.h"
#include "Model/square.h"

class Game
{
    Renderer* m_renderer;

    std::shared_ptr<Square> test_square;

    std::shared_ptr<Square> ground_plane;
    std::shared_ptr<Square> top_plane;
    std::shared_ptr<Square> right_plane;
    std::shared_ptr<Square> left_plane;
    std::shared_ptr<Square> front_plane;
    std::shared_ptr<Square> back_plane;
	std::shared_ptr<Model> plane;
public:
    Game(Renderer* renderer);
    void initialize();
    void update(double delta);
};

#endif // GAME_H
