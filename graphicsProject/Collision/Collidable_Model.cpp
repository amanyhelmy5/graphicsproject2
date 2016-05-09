#include "Collidable_Model.h"


Collidable::Collidable(void)
{
}


Collidable::~Collidable(void)
{
}

void Collidable::Set_BoundingBox(Bounding_Box fBoundingBox)
{
	boundingBox = fBoundingBox;
}

Bounding_Box Collidable::Get_BoundingBox()
{
	return boundingBox;
}

Bounding_Box Collidable::CalculateBoundingBox(std::vector<glm::vec3> vertices, float boxOffset /*= 0.0f*/)
{
	glm::vec3 boxMin = glm::vec3(99999999.0f);
	glm::vec3 boxMax = glm::vec3(-99999999.0f);

	for (int i = 0; i < vertices.size(); i++)
	{
		//check each dimension
		for (int j = 0; j < 3; j++)
		{
			if (boxMin[j] > vertices[i][j])
			{
				boxMin[j] = vertices[i][j];
			}
			if (boxMax[j] < vertices[i][j])
			{
				boxMax[j] = vertices[i][j];
			}
		}
	}
	glm::vec3 boxCenter = (boxMax + boxMin) / 2.0f;
	glm::vec3 boxSize = boxMax - boxMin;
	//if we want to make the box larger or smaller than the original object's bounding box.
	boxSize += boxOffset;

	if (boxSize.x <0.0f || boxSize.y<0.0f || boxSize.z<0.0f)
	{
		throw std::runtime_error("ERROR: bounding box size cannot be less than zero!");
	}

	Bounding_Box box(glm::vec3(0), boxSize);
	return box;
}

void Collidable::Collided()
{
	//we just want to display the address of the collided object to make sure that collision happened for each object.
	printf("I've collided! my address is %p \n", static_cast<void const *>(this));
}