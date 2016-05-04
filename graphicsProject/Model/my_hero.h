#include "Model.h"

#include "../Collision/Collidable_Model.h"

class  my_hero : Model, Collidable_Model
{
public:
	 my_hero();
	~my_hero();
	void initialize();
	std::vector<glm::vec3> vertex_data;
private:

};
