#include "Model.h"
#include <string>

#include "../Collision/Collidable_Model.h"

class  my_hero : public Model, public Collidable_Model
{
public:
	 my_hero();
     my_hero(std::string path);
	 my_hero(std::string model_path, std::string path);
	~my_hero();
	void initialize();
	virtual std::vector<glm::vec3> get_vertex_data(){ return vertex_data; }
	Bounding_Box bounding_box;
private:

};
