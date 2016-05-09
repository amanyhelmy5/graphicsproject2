#include "Model.h"
#include <string>

#include "../Collision/Collidable_Model.h"

class  Collidable_Model : public Model, public Collidable
{
public:
     Collidable_Model();
     Collidable_Model(std::string path);
     Collidable_Model(std::string model_path, std::string path);
    ~Collidable_Model();
	void initialize();
	virtual std::vector<glm::vec3> get_vertex_data(){ return vertex_data; }
	Bounding_Box bounding_box;
private:

};
