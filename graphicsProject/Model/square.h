#ifndef SQUARE_H
#define SQUARE_H
#include "Model.h"

#define RED 0
#define GREEN 1
#define BLUE 2

class Square : public Model
{
    glm::vec3 m_color;
public:
    Square(int color);
    Square(std::string path);
};

#endif // SQUARE_H
