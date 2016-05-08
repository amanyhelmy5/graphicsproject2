
#include"my_hero.h"


my_hero::my_hero()
{
	vertex_data = Model::vertex_data;
}

my_hero::my_hero(std::string path) : Model(path)
{
}

my_hero::my_hero(std::string model_path, std::string path) : Model(model_path, path)
{
}

my_hero::~my_hero()
{
}

void::my_hero::initialize()
{
	Model::initialize();
	Collidable_Model::Set_BoundingBox(CalculateBoundingBox(get_vertices()));
	
}
