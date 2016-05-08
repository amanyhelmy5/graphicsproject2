#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Renderer/Renderer.h"
#include "Model/square.h"

#include "actions.h"

class Game
{
protected:
    Renderer* m_renderer;

    std::shared_ptr<Square> test_square;
	//std::shared_ptr<Model> plane;
	//std::shared_ptr<Model> body;

    float angle = 0.0f;

    std::shared_ptr<Model> spider;
    std::shared_ptr<Model> skybox;
public:
    Game(Renderer* renderer);
    virtual void initialize();
    void update(float delta, Actions p_actions);
};

#endif // GAME_H
