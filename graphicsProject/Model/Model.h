#ifndef Model_h__
#define Model_h__

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtx/rotate_vector.hpp>
#include <gtc/quaternion.hpp>
#include <gtx/quaternion.hpp>

#include <vector>
#include <memory>
#include <iostream>


#ifdef __linux__
    #include <GL/glew.h>
#elif _WIN32
    #include <gl/glew.h>
#endif

#include "../Texture/texture.h"
#include "../objloader.hpp"
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

	std::vector<glm::vec3> color_data;
	std::vector<unsigned short> indices_data;
	std::vector<glm::vec2> UV_data;

	std::vector<glm::vec3>	normals_data;
protected:
	std::vector<glm::vec3> vertex_data;
    std::unique_ptr<Texture> m_texture;

	glm::vec3 m_position;
	glm::vec3 m_direction;
    glm::vec3 m_scale;
    glm::vec4 m_rotation;

    glm::mat4 m_model_matrix;

    glm::mat4 m_translation_matrix;
    glm::mat4 m_rotation_matrix;
    glm::mat4 m_scale_matrix;
public:
	Model();
    Model(std::string path);
    Model(std::string model_path, std::string path);

	~Model();

	char* m_model_path;
	std::string pathfile;

	virtual std::vector<glm::vec3> get_vertex_data() = 0;

     void initialize();
     void draw();
     void set_texture(std::string path);
     void bind_texture();
     void clean_up();

	 void set_direction(glm::vec3 direction);
	 glm::vec3 get_direction();
	 glm::vec3 get_position();
	 void set_position(glm::vec3 position);
	 void move();
	 std::vector<glm::vec3> get_vertices();

     glm::mat4 get_model_matrix() const;
     void set_translation(float x, float y, float z);
     void set_rotation(float angle, float x, float y, float z);
     void set_scale(float x, float y, float z);

     void move(float x, float y, float z);
     void rotate(float angle, float x, float y, float z);
     void scale(float x, float y, float z);

};
#endif // Model_h__

