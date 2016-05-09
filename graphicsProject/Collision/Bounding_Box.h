#ifndef Bounding_Box_h__
#define Bounding_Box_h__
#include <glm.hpp>
#include <gtx/transform.hpp>


class Bounding_Box
{
	glm::vec3 size;
	glm::vec3 center;
	glm::vec3 halfSize;
public:
	Bounding_Box();
	Bounding_Box(glm::vec3 fCenter, glm::vec3 fSize);
	~Bounding_Box(void);

	void SetCenter(glm::vec3 fCenter);
	void SetSize(glm::vec3 fSize);

	inline glm::vec3 GetCenter() { return center; }
	inline glm::vec3 GetSize() { return size; }
	inline glm::vec3 GetHalfSize() { return halfSize; }

	bool IsIntersecting(Bounding_Box box);

	void Scale(glm::vec3 scale);
	void Scale(float scaleX, float scaleY, float scaleZ);
	void Translate(glm::vec3 translation);
	void Translate(float translateX, float translateY, float translateZ);
	void Rotate(glm::mat4 rotationMatrix);
	void Rotate(float angle, float axisX, float axisY, float axisZ);
};

#endif //Bounding_Box_h__
