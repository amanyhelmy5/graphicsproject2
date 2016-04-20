#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

#ifdef __linux__
    #include <GL/glew.h>
#elif _WIN32
    #include <gl/glew.h>
#endif

class Texture
{

public:
	/*unsigned*/ int width, height;
	int numComponents;
	unsigned char * data;
	int texUnit;
	void Bind();
	Texture(const std::string& fileName, int texUnit);
	virtual ~Texture();

protected:
private:
	Texture(const Texture& texture) {}
	void operator=(const Texture& texture) {}
	GLuint m_texture;
};

#endif
//GLuint loadBMP_custom(const char * imagepath);
