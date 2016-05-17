#ifndef Collidable_Model_h__
#define Collidable_Model_h__

#include "Bounding_Box.h"

#include <stdexcept>
#include <vector>
#include <glm.hpp>
#include "types.h"

class Collidable
{
protected:

	Bounding_Box boundingBox;

public:
    Collidable();
    virtual ~Collidable();
	void Set_BoundingBox(Bounding_Box fBoundingBox);
	Bounding_Box Get_BoundingBox();

    state m_state;
    ana_meen m_ana_meen;

    void destroy();
    bool is_dead();

	static Bounding_Box CalculateBoundingBox(std::vector<glm::vec3> vertices, float boxOffset = 0.0f);
    virtual void Collided(Collidable* body);

};
#endif // Collidable_Model_h__
