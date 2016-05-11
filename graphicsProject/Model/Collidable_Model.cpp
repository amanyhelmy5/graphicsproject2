
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

void Collidable_Model::set_translation(float x, float y, float z)
{
    m_position = glm::vec3(x, y, z);
    bounding_box.Translate(x, y, z);
}

void Collidable_Model::set_rotation(float angle, float x, float y, float z)
{
    m_rotation = glm::vec4(angle, x, y, z);
}

void Collidable_Model::set_scale(float x, float y, float z)
{
    m_scale = glm::vec3(x, y, z);
    bounding_box.Scale(x, y, z);
}

void Collidable_Model::rotate(float angle, float x, float y, float z)
{
    m_rotation.w += angle;
    m_rotation.x = x;
    m_rotation.y = y;
    m_rotation.z = z;
    bounding_box.Rotate(angle, x, y, z);
}

void Collidable_Model::scale(float x, float y, float z)
{
    m_scale.x += x;
    m_scale.y += y;
    m_scale.z += z;
    bounding_box.Scale(x, y, z);
}

void Collidable_Model::move(float x, float y, float z)
{
    m_position.x += x;
    m_position.y += y;
    m_position.z += z;
    bounding_box.Translate(x, y, z);
}
