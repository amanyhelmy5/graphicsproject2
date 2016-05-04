#include "square.h"
Square::Square()
{

}
Square::Square(int color)
{
    vertex_data.push_back(glm::vec3(-1.0f, 1.0f, 0.0f));
    vertex_data.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
    vertex_data.push_back(glm::vec3(-1.0f, -1.0f, 0.0f));
    vertex_data.push_back(glm::vec3(1.0f, -1.0f, 0.0f));

    indices_data.push_back(0);
    indices_data.push_back(1);
    indices_data.push_back(3);
    indices_data.push_back(0);
    indices_data.push_back(2);
    indices_data.push_back(3);

    if (color == RED)
        m_color = glm::vec3(1.0f, 0.0f, 0.0f);
    else if (color == GREEN)
        m_color = glm::vec3(0.0f, 1.0f, 0.0f);
    else if (color == BLUE)
        m_color = glm::vec3(0.0f, 0.0f, 1.0f);

    color_data.push_back(m_color);
    color_data.push_back(m_color);
    color_data.push_back(m_color);
    color_data.push_back(m_color);
    color_data.push_back(m_color);
    color_data.push_back(m_color);

    initialize();
}

Square::Square(std::string path)
{
    //drawing a square.

    vertex_data.push_back(glm::vec3(-1.0f, -1.0f, 0.0f));
    vertex_data.push_back(glm::vec3(1.0f, -1.0f, 0.0f));
    vertex_data.push_back(glm::vec3( 1.0f,  1.0f, 0.0f));
    vertex_data.push_back(glm::vec3( -1.0f,  1.0f, 0.0f));

    color_data.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
    color_data.push_back(glm::vec3(0.0f, 0.0f, 0.5f));
    color_data.push_back(glm::vec3(0.0f, 0.0f, 0.5f));
    color_data.push_back(glm::vec3(1.0f, 0.0f, 0.5f));

    UV_data.push_back(glm::vec2(0.0f,0.0f));
    UV_data.push_back(glm::vec2(1.0f,0.0f));
    UV_data.push_back(glm::vec2(0.0f,1.0f));
    UV_data.push_back(glm::vec2(1.0f,1.0f));

    indices_data.push_back(0);
    indices_data.push_back(1);
    indices_data.push_back(3);

    indices_data.push_back(1);
    indices_data.push_back(2);
    indices_data.push_back(3);

    set_texture(path);
    initialize();
}
