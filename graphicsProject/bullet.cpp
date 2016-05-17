#include "bullet.h"


bullet::bullet(glm::vec3 position,glm::vec3 direction)
{
	m_position = position;
	m_direction = direction;
	boundingBox = Bounding_Box(position, glm::vec3(0.5f, 0.5f, 0.5f));
	//boundingBox = Bounding_Box::Translate(float translateX, float translateY, float translateZ)

	this->boundingBox.Translate(translatex, translarey, translatez);
	{
		translatex += translatex;
	}

	
}


bullet::~bullet(void)
{
}

//void bullet::Set_BoundingBox(Bounding_Box fBoundingBox)
//{
//	boundingBox = fBoundingBox;
//}
//
//Bounding_Box bullet::Get_BoundingBox()
//{
//	return boundingBox;
//}
//
