#include "bullet.h"


Bullet::Bullet(glm::vec3 position, glm::vec3 direction, Collision_Manager* collision_manager)
{
    m_ana_meen = ana_meen::BULLET;
    m_collision_manager = collision_manager;
	m_position = position;
	m_direction = direction;
	boundingBox = Bounding_Box(position, glm::vec3(0.5f, 0.5f, 0.5f));

    m_collision_manager->AddCollidableModel((Collidable*)this);

    int step=9999;

    while(step)
    {
        //m_position = m_direction/4.0f + m_position;
        boundingBox.Translate(m_direction);
        m_collision_manager->UpdateCollisions();
        step--;
    }

    m_collision_manager->RemoveCollidableModel((Collidable*)this);

}


Bullet::~Bullet(void)
{

}

void Bullet::destroy()
{
    m_state = state::DEAD;
}

bool Bullet::is_dead()
{
    if (m_state == state::DEAD)
        return true;
    else
        return false;
}

void Bullet::Collided(Collidable* body)
{
    std::cout << "ana bullet" << std::endl;
    destroy();
}
