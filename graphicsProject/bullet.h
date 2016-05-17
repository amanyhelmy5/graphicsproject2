#ifndef BULLET_H
#define BULLET_H
#include "Collision/Collidable.h"
#include "Collision/Collision_Manager.h"
#include <iostream>

class Bullet : public Collidable
{   
	glm::vec3 m_position;
    glm::vec3 m_direction;
    Collision_Manager* m_collision_manager;
	
public:
    Bullet();
    Bullet(glm::vec3 m_position, glm::vec3  m_direction, Collision_Manager* collision_manager);
    ~Bullet();

    ana_meen m_ana_meen;
    state m_state;

    void destroy();

    bool is_dead();

    virtual void Collided(Collidable* body);
};
#endif
