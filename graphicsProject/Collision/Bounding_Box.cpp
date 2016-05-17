#include "Bounding_Box.h"
#include "Collidable.h"




Bounding_Box::Bounding_Box()
{
	SetCenter(glm::vec3(0));
	SetSize(glm::vec3(0));
}

Bounding_Box::Bounding_Box(glm::vec3 fCenter, glm::vec3 fSize)
{
	SetCenter(fCenter);
	SetSize(fSize);
}

Bounding_Box::~Bounding_Box(void)
{

}

void Bounding_Box::SetCenter(glm::vec3 fCenter)
{
	center = fCenter;
}

void Bounding_Box::SetSize(glm::vec3 fSize)
{//zodel_In
	size = fSize;
	halfSize = size / 2.0f;
}

bool Bounding_Box::IsIntersecting(Bounding_Box box)
{
	glm::vec3 absoluteDistance = glm::abs(this->center - box.GetCenter());
	glm::vec3 totalHalfSize = this->GetHalfSize() + box.GetHalfSize();
	if (absoluteDistance.x < totalHalfSize.x
		&&	absoluteDistance.y < totalHalfSize.y
		&&	absoluteDistance.z < totalHalfSize.z)
	{
		return true;
	}
	return false;
}

void Bounding_Box::Scale(glm::vec3 scale)
{
	glm::vec3 scaledSize = this->size * scale;
	glm::vec3 scaledCenter = this->center *scale;
	SetSize(scaledSize);
	SetCenter(scaledCenter);
}

void Bounding_Box::Scale(float scaleX, float scaleY, float scaleZ)
{
	glm::vec3 scale = glm::vec3(scaleX, scaleY, scaleZ);
	Scale(scale);
}

void Bounding_Box::Translate(glm::vec3 translation)
{
	glm::vec3 translatedCenter = this->center + translation;
	SetCenter(translatedCenter);
}

void Bounding_Box::Translate(float translateX, float translateY, float translateZ)
{
	glm::vec3 translation = glm::vec3(translateX, translateY, translateZ);
	Translate(translation);
}

void Bounding_Box::Rotate(glm::mat4 rotationMatrix)
{
	
#pragma region another solution to be tested
	std::vector<glm::vec3> corners;
	int numberOfCorners = 4;
	corners.resize(numberOfCorners);
	for (int i = 0; i < corners.size(); i++)
	{
		corners[i] = halfSize;
	}
	corners[1].y *= -1;
	corners[2].z *= -1;
	corners[3].y *= -1;
	corners[3].z *= -1;
	for (int i = 0; i < corners.size(); i++)
	{
		corners[i] = glm::vec3(rotationMatrix*glm::vec4(corners[i], 1));
	}
	for (int i = 0; i < numberOfCorners; i++)
	{
		corners.push_back(corners[i] * -1.0f);
	}
	auto cornersBox = Collidable::CalculateBoundingBox(corners);
	SetSize(cornersBox.GetSize());
#pragma endregion another solution to be tested

}

void Bounding_Box::Rotate(float angle, float axisX, float axisY, float axisZ)
{
	glm::mat4 rotationMatrix = glm::rotate(angle, axisX, axisY, axisZ);
	Rotate(rotationMatrix);
}
