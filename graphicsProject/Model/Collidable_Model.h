#include "Model.h"
#include <string>

#include "../Collision/Collidable.h"

class  Collidable_Model : public Model, public Collidable
{
public:
     Collidable_Model();
     Collidable_Model(std::string path);
     Collidable_Model(std::string model_path, std::string path);
    ~Collidable_Model();
	void initialize();
    virtual void set_translation(float x, float y, float z);
    virtual void set_rotation(float angle, float x, float y, float z);
    virtual void set_scale(float x, float y, float z);

    virtual void move(float x, float y, float z);
    virtual void rotate(float angle, float x, float y, float z);
    virtual void scale(float x, float y, float z);
	virtual std::vector<glm::vec3> get_vertex_data(){ return vertex_data; }
	Bounding_Box bounding_box;
private:

};
