#ifndef Model_h__
#define Model_h__

#include <glm.hpp>
#include <vector>
#include <memory>
#include <iostream>

#ifdef __linux__
    #include <GL/glew.h>
#elif _WIN32
    #include <gl/glew.h>
#endif
#include "../ShaderProgram/ShaderProgram.h"

#include "../Texture/texture.h"
#include "../objloader.hpp"
class Model
{
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
public:
	Model();
    Model(std::string path);
	Model(std::string path,char* modelpath);

	~Model();

    std::vector<glm::vec3> vertex_data;
    std::vector<glm::vec3> color_data;
    std::vector<unsigned short> indices_data;
    std::vector<glm::vec2> UV_data;
	std::vector<glm::vec3>	normals_data;
    glm::mat4 model_matrix;
	char* m_model_path;
     void initialize();
     void draw();
     void set_texture(std::string path);
     void bind_texture();
     void clean_up();
};
#endif // Model_h__

