#ifndef GraphicsDevice_h__
#define GraphicsDevice_h__

#ifdef __linux__
    #include <GL/glew.h>
#elif _WIN32
    #include <gl/glew.h>
#endif
#include "../Shaders/shader.hpp"


class ShaderProgram
{
	public:
	GLuint programID;

	GLuint modelMatrixID;
	GLuint vpMatrixID;

	ShaderProgram();
	~ShaderProgram();

	void BindModelMatrix(GLfloat* value);
	void BindVPMatrix(GLfloat* value);
	
	//calls glUseProgram.
	void UseProgram();
	//load shaders from files.
	void LoadProgram();
	void CleanUp();
};

#endif // GraphicsDevice_h__
