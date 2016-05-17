#ifndef Collidable_Model_h__
#define Collidable_Model_h__

#include "Bounding_Box.h"

#include <stdexcept>
#include <vector>
#include <glm.hpp>

class Collidable
{
protected:

	Bounding_Box boundingBox;

public:
	Collidable(void);
	~Collidable(void);
	void Set_BoundingBox(Bounding_Box fBoundingBox);
	Bounding_Box Get_BoundingBox();

	static Bounding_Box CalculateBoundingBox(std::vector<glm::vec3> vertices, float boxOffset = 0.0f);
    //to handles different collision
	virtual void Collided();

};
#endif // Collidable_Model_h__
