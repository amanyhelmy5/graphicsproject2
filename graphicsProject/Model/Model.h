#ifndef Model_h__
#define Model_h__

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtx/rotate_vector.hpp>
#include <gtc/quaternion.hpp>
#include <gtx/quaternion.hpp>

#include <vector>
#include <memory>
#include <string>

#ifdef __linux__
    #include <GL/glew.h>
#elif _WIN32
    #include <gl/glew.h>
#endif

#include "../Texture/texture.h"

class Model
{
    friend class Game;
	//VAO
    GLuint m_vertex_array_object_ID;
	
	//VBOs
    GLuint m_vertex_data_buffer_ID; //vertex data buffer ID
    GLuint m_color_data_buffer_ID;
    GLuint m_indices_data_buffer_ID;
    GLuint m_UV_data_buffer_ID;
protected:
    std::unique_ptr<Texture> m_texture;
    /*std::vector<glm::vec3> m_normal_data;
    std::vector<glm::vec2> mUV_data;*/

    glm::mat4 m_model_matrix;

    glm::mat4 m_translation_matrix;
    glm::mat4 m_rotation_matrix;
    glm::mat4 m_scale_matrix;

    glm::vec3 m_position;
    glm::vec3 m_scale;
    glm::vec4 m_rotation;
public:
	Model();
    Model(std::string path);
	~Model();

    std::vector<glm::vec3> vertex_data;
    std::vector<glm::vec3> color_data;
    std::vector<unsigned short> indices_data;
    std::vector<glm::vec2> UV_data;

     void initialize();
     void draw();
     void set_texture(std::string path);
     void bind_texture();
     void clean_up();
     glm::mat4 model_matrix() const;
     void set_translation(float x, float y, float z);
     void set_rotation(float angle, float x, float y, float z);
     void set_scale(float x, float y, float z);

     void move(float x, float y, float z);
     void rotate(float angle, float x, float y, float z);
     void scale(float x, float y, float z);
};
#endif // Model_h__

