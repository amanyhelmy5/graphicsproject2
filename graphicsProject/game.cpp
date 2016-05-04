#include "game.h"


Game::Game(Renderer * renderer, Collision_Manager * collision_manager)
{
	m_renderer = renderer;
	m_collisionmanager = collision_manager;
}


void Game::initialize()
{
    test_square  =   std::shared_ptr<my_hero> (new Square("uvtemplate.bmp"));
    ground_plane =   std::shared_ptr<Square> (new Square("ground.png"));
    top_plane    =   std::shared_ptr<Square> (new Square("top.png"));
    right_plane  =   std::shared_ptr<Square> (new Square("right.png"));
    left_plane   =   std::shared_ptr<Square> (new Square("left.png"));
    front_plane  =   std::shared_ptr<Square> (new Square("front.png"));

	test_square->model_matrix = glm::scale(1.0f, 1.0f, 1.0f) * glm::translate(0.0f, 0.0f, 0.0f) * glm::rotate(0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
    ground_plane->model_matrix = glm::translate(0.0f, -500.0f, 0.0f) * glm::rotate(180.0f, 0.0f, 1.0f, 0.0f) * glm::rotate(90.0f, -1.0f, 0.0f, 0.0f) * glm::scale(500.0f, 500.0f, 500.0f);
    top_plane   ->model_matrix = glm::translate(0.0f, 100.0f, 0.0f)  * glm::rotate(180.0f, 0.0f, 1.0f, 0.0f) * glm::rotate(90.0f, 1.0f, 0.0f, 0.0f)  * glm::scale(500.0f, 500.0f, 500.0f); //fo2
    right_plane ->model_matrix = glm::translate(0.0f, 0.0f, -500.0f) * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f)                                         * glm::scale(500.0f, 500.0f, 500.0f);
    left_plane  ->model_matrix = glm::translate(500.0f, 0.0f, 0.0f)  * glm::rotate(90.0f, 0.0f, -1.0f, 0.0f) * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f) * glm::scale(500.0f, 500.0f, 500.0f);
    front_plane ->model_matrix = glm::translate(-500.0f, 0.0f, 0.0f) * glm::rotate(90.0f, 0.0f, 1.0f, 0.0f)  * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f) * glm::scale(500.0f, 500.0f, 500.0f);
    back_plane  ->model_matrix = glm::translate(0.0f, 0.0f, 500.0f)  * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f) * glm::rotate(180.0f, 0.0f, 1.0f, 0.0f) * glm::scale(500.0f, 500.0f, 500.0f);

    m_renderer->add_model(test_square );
    m_renderer->add_model(ground_plane);
    m_renderer->add_model(top_plane   );
    m_renderer->add_model(right_plane );
    m_renderer->add_model(left_plane  );
	m_renderer->add_model(front_plane); 
    m_renderer->add_model(back_plane  );

	m_collisionmanager->AddCollidableModel((Collidable_Model*)test_square.get());
	m_collisionmanager->AddCollidableModel((Collidable_Model*)ground_plane.get());
	m_collisionmanager->AddCollidableModel((Collidable_Model*)top_plane.get());
	m_collisionmanager->AddCollidableModel((Collidable_Model*)right_plane.get());
	m_collisionmanager->AddCollidableModel((Collidable_Model*)left_plane.get());
	m_collisionmanager->AddCollidableModel((Collidable_Model*)front_plane.get());
	m_collisionmanager->AddCollidableModel((Collidable_Model*)back_plane.get());
}

void Game::update(double delta)
{
	test_square->model_matrix = glm::scale(1.0f, 1.0f, 1.0f) * glm::translate(0.0f,x , 0.0f) * glm::rotate(0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	x += 0.05;
}

