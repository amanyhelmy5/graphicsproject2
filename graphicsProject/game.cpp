#include "game.h"

Game::Game(Renderer* renderer)
{
    mRenderer = renderer;
}


void Game::Initialize()
{
    test_square  =   std::shared_ptr<Square> (new Square("uvtemplate.bmp"));
    ground_plane =   std::shared_ptr<Square> (new Square("ground.png"));
    top_plane    =   std::shared_ptr<Square> (new Square("top.png"));
    right_plane  =   std::shared_ptr<Square> (new Square("right.png"));
    left_plane   =   std::shared_ptr<Square> (new Square("left.png"));
    front_plane  =   std::shared_ptr<Square> (new Square("front.png"));
    back_plane   =   std::shared_ptr<Square> (new Square("back.png"));

    test_square ->model_matrix = glm::scale(1.0f, 1.0f, 1.0f) * glm::translate(0.0f, 0.0f, 0.0f) * glm::rotate(0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    ground_plane->model_matrix = glm::translate(0.0f, -500.0f, 0.0f) * glm::rotate(180.0f, 0.0f, 1.0f, 0.0f) * glm::rotate(90.0f, -1.0f, 0.0f, 0.0f) * glm::scale(500.0f, 500.0f, 500.0f);
    top_plane   ->model_matrix = glm::translate(0.0f, 100.0f, 0.0f)  * glm::rotate(180.0f, 0.0f, 1.0f, 0.0f) * glm::rotate(90.0f, 1.0f, 0.0f, 0.0f)  * glm::scale(500.0f, 500.0f, 500.0f); //fo2
    right_plane ->model_matrix = glm::translate(0.0f, 0.0f, -500.0f) * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f)                                         * glm::scale(500.0f, 500.0f, 500.0f);
    left_plane  ->model_matrix = glm::translate(500.0f, 0.0f, 0.0f)  * glm::rotate(90.0f, 0.0f, -1.0f, 0.0f) * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f) * glm::scale(500.0f, 500.0f, 500.0f);
    front_plane ->model_matrix = glm::translate(-500.0f, 0.0f, 0.0f) * glm::rotate(90.0f, 0.0f, 1.0f, 0.0f)  * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f) * glm::scale(500.0f, 500.0f, 500.0f);
    back_plane  ->model_matrix = glm::translate(0.0f, 0.0f, 500.0f)  * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f) * glm::rotate(180.0f, 0.0f, 1.0f, 0.0f) * glm::scale(500.0f, 500.0f, 500.0f);

    mRenderer->add_model(test_square );
    mRenderer->add_model(ground_plane);
    mRenderer->add_model(top_plane   );
    mRenderer->add_model(right_plane );
    mRenderer->add_model(left_plane  );
    mRenderer->add_model(front_plane );
    mRenderer->add_model(back_plane  );
}

void Game::Update(double delta)
{

}
