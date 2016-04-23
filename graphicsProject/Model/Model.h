#ifndef Model_h__
#define Model_h__

#include <glm.hpp>
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
	//VAO
	GLuint mVertexArrayObjectID;
	
	//VBOs
	GLuint mVertexDataBufferID;
	GLuint mColorDataBufferID;
	GLuint mIndicesDataBufferID;
	GLuint mUVDataBufferID;
protected:
    std::unique_ptr<Texture> mTexture;
	/*std::vector<glm::vec3> mNormalData;
	std::vector<glm::vec2> mUVData;*/
public:
	Model();
    Model(std::string path);
	~Model();

	std::vector<glm::vec3> VertexData;
	std::vector<glm::vec3> ColorData;
	std::vector<unsigned short> IndicesData;
	std::vector<glm::vec2> UVData;
    glm::mat4 model_matrix;

	 void Initialize();
	 void Draw();
     void set_texture(std::string path);
     void bind_texture();
	 void Cleanup();
};
#endif // Model_h__

