
#include"Collidable_Model.h"


Collidable_Model::Collidable_Model()
{
}

Collidable_Model::Collidable_Model(std::string path) : Model(path)
{
}

Collidable_Model::Collidable_Model(std::string model_path, std::string path) : Model(model_path, path)
{
	initialize();
}

Collidable_Model::~Collidable_Model()
{
}

void Collidable_Model::initialize()
{
	bounding_box = Collidable::CalculateBoundingBox(vertex_data);
	Set_BoundingBox(bounding_box);
}
