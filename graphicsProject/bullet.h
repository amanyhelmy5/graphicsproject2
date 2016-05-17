#ifndef BULLET_H
#define BULLET_H
#include "Collision/Collidable.h"

class bullet : public Collidable
{
	glm::vec3 m_position;
	glm::vec3 m_direction;
	float translatex;
	float translarey;
	float translatez;
	
public:
	bullet();
	~bullet();
	//void Set_BoundingBox(Bounding_Box fBoundingBox);
	//Bounding_Box Get_BoundingBox();
		bullet(glm::vec3 m_position, glm::vec3  m_direction);

};
#endif
