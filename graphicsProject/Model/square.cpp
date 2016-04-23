#include "square.h"

Square::Square(int color)
{
    VertexData.push_back(glm::vec3(-1.0f, 1.0f, 0.0f));
    VertexData.push_back(glm::vec3(1.0f, 1.0f, 0.0f));
    VertexData.push_back(glm::vec3(-1.0f, -1.0f, 0.0f));
    VertexData.push_back(glm::vec3(1.0f, -1.0f, 0.0f));

    IndicesData.push_back(0);
    IndicesData.push_back(1);
    IndicesData.push_back(3);
    IndicesData.push_back(0);
    IndicesData.push_back(2);
    IndicesData.push_back(3);

    if (color == RED)
        m_color = glm::vec3(1.0f, 0.0f, 0.0f);
    else if (color == GREEN)
        m_color = glm::vec3(0.0f, 1.0f, 0.0f);
    else if (color == BLUE)
        m_color = glm::vec3(0.0f, 0.0f, 1.0f);

    ColorData.push_back(m_color);
    ColorData.push_back(m_color);
    ColorData.push_back(m_color);
    ColorData.push_back(m_color);
    ColorData.push_back(m_color);
    ColorData.push_back(m_color);

    Initialize();
}

Square::Square(std::string path)
{
    //drawing a square.

    VertexData.push_back(glm::vec3(-1.0f, -1.0f, 0.0f));
    VertexData.push_back(glm::vec3(1.0f, -1.0f, 0.0f));
    VertexData.push_back(glm::vec3( 1.0f,  1.0f, 0.0f));
    VertexData.push_back(glm::vec3( -1.0f,  1.0f, 0.0f));

    ColorData.push_back(glm::vec3(1.0f, 0.0f, 0.5f));
    ColorData.push_back(glm::vec3(0.0f, 0.0f, 0.5f));
    ColorData.push_back(glm::vec3(0.0f, 0.0f, 0.5f));
    ColorData.push_back(glm::vec3(1.0f, 0.0f, 0.5f));

    UVData.push_back(glm::vec2(0.0f,0.0f));
    UVData.push_back(glm::vec2(1.0f,0.0f));
    UVData.push_back(glm::vec2(0.0f,1.0f));
    UVData.push_back(glm::vec2(1.0f,1.0f));

    IndicesData.push_back(0);
    IndicesData.push_back(1);
    IndicesData.push_back(3);

    IndicesData.push_back(1);
    IndicesData.push_back(2);
    IndicesData.push_back(3);

    set_texture(path);
    Initialize();
}
