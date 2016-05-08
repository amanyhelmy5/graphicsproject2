
#include"my_hero.h"


my_hero::my_hero()
{
}

my_hero::my_hero(std::string path) : Model(path)
{
}

my_hero::my_hero(std::string model_path, std::string path) : Model(model_path, path)
{
	initialize();
}

my_hero::~my_hero()
{
}

void::my_hero::initialize()
{
	bounding_box = Collidable_Model::CalculateBoundingBox(vertex_data);
	Set_BoundingBox(bounding_box);
	
	
}
