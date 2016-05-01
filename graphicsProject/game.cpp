#include "game.h"

Game::Game(Renderer* renderer)
{
    m_renderer = renderer;
}


void Game::initialize()
{
    test_square  =   std::shared_ptr<Square> (new Square("uvtemplate.bmp"));
    ground_plane =   std::shared_ptr<Square> (new Square("ground.png"));
    top_plane    =   std::shared_ptr<Square> (new Square("top.png"));
    right_plane  =   std::shared_ptr<Square> (new Square("right.png"));
    left_plane   =   std::shared_ptr<Square> (new Square("left.png"));
    front_plane  =   std::shared_ptr<Square> (new Square("front.png"));
    back_plane   =   std::shared_ptr<Square> (new Square("back.png"));

//    test_square ->m_model_matrix = glm::scale(1.0f, 1.0f, 1.0f) * glm::translate(0.0f, 0.0f, 0.0f) * glm::rotate(0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
//    ground_plane->m_model_matrix = glm::translate(0.0f, -500.0f, 0.0f) * glm::rotate(180.0f, 0.0f, 1.0f, 0.0f) * glm::rotate(90.0f, -1.0f, 0.0f, 0.0f) * glm::scale(500.0f, 500.0f, 500.0f);
//    top_plane   ->m_model_matrix = glm::translate(0.0f, 100.0f, 0.0f)  * glm::rotate(180.0f, 0.0f, 1.0f, 0.0f) * glm::rotate(90.0f, 1.0f, 0.0f, 0.0f)  * glm::scale(500.0f, 500.0f, 500.0f); //fo2
//    right_plane ->m_model_matrix = glm::translate(0.0f, 0.0f, -500.0f) * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f)                                         * glm::scale(500.0f, 500.0f, 500.0f);
//    left_plane  ->m_model_matrix = glm::translate(500.0f, 0.0f, 0.0f)  * glm::rotate(90.0f, 0.0f, -1.0f, 0.0f) * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f) * glm::scale(500.0f, 500.0f, 500.0f);
//    front_plane ->m_model_matrix = glm::translate(-500.0f, 0.0f, 0.0f) * glm::rotate(90.0f, 0.0f, 1.0f, 0.0f)  * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f) * glm::scale(500.0f, 500.0f, 500.0f);
//    back_plane  ->m_model_matrix = glm::translate(0.0f, 0.0f, 500.0f)  * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f) * glm::rotate(180.0f, 0.0f, 1.0f, 0.0f) * glm::scale(500.0f, 500.0f, 500.0f);

    test_square ->set_rotation(0.0f, 1.0f, 0.0f, 0.0f);
    test_square ->set_scale(1.0f, 1.0f, 1.0f);
    test_square ->set_translation(0.0f, 0.0f, -10.0f);

    ground_plane->rotate(90.0f, -1.0f, 0.0f, 0.0f);
    ground_plane->set_scale(500.0f, 500.0f, 500.0f);
    ground_plane->set_translation(0.0f, -500.0f, 0.0f);

    top_plane   ->rotate(90.0f, 1.0f, 0.0f, 0.0f);
    top_plane   ->set_scale(500.0f, 500.0f, 500.0f);
    top_plane   ->set_translation(0.0f, 500.0f, 0.0f);

    front_plane   ->rotate(180.0f, 0.0f, 0.0f, 1.0f);
    front_plane   ->set_scale(500.0f, 500.0f, 500.0f);
    front_plane   ->set_translation(0.0f, 0.0f, -500.0f);

    back_plane   ->rotate(180.0f, 1.0f, 0.0f, 0.0f);
    back_plane   ->set_scale(500.0f, 500.0f, 500.0f);
    back_plane   ->set_translation(0.0f, 0.0f, 500.0f);

    //right_plane   ->set_rotation(45.0f, 0.0f, 1.0f, 0.0f);
    //right_plane   ->rotate(180.0f, 0.0f, 1.0f, 0.0f);
    right_plane   ->set_scale(500.0f, 500.0f, 500.0f);
    right_plane   ->set_translation(-500.0f, 0.0f, 0.0f);

    m_renderer->add_model(test_square );
    m_renderer->add_model(ground_plane);
    m_renderer->add_model(top_plane   );
    m_renderer->add_model(right_plane );
    m_renderer->add_model(left_plane  );
    m_renderer->add_model(front_plane );
    m_renderer->add_model(back_plane  );
}

void Game::update(float delta)
{
    //test_square->rotate(delta*0.1f, 0.0f, 0.0f, 1.0f);
    test_square->set_scale(delta*angle, delta*angle, delta*angle);
    //right_plane->rotate(angle*delta, 0.0f, 1.0f, 0.0f);
    angle += 1.1f;
}
