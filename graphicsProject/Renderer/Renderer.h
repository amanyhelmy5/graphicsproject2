#ifndef Renderer_h__
#define Renderer_h__

#ifdef __linux__
    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
#elif _WIN32
    #include <gl/glew.h>
    #include <gl/glfw3.h>
#endif


#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <memory>


#include "../Shaders/shader.hpp"
#include "../Texture/texture.h"
#include "../Model/Model.h"
#include "../Model/square.h"
#include "../EulerCamera/EulerCamera.h"
#include "../actions.h"

class Renderer
{
	enum RenderingMode
	{
		NO_TEXTURE,
		TEXTURE_ONLY,
		BLEND
	};

	GLuint programID;

	// Transformation
	GLuint MatrixID;

    std::vector< std::shared_ptr<Model> > models;

	std::unique_ptr<EulerCamera> myCamera;


	GLuint mRenderingModeID;
	RenderingMode mRenderingMode;

    Actions actions;


public:
	Renderer();
	~Renderer();

	void Initialize();
	void Draw();
    void HandleKeyboardInput(Actions);//Actions);
	void HandleMouse(double deltaX,double deltaY);
	void Update(double deltaTime);
	void Cleanup();

    void add_model(std::shared_ptr<Model> model);

	void initShader();
	void initTransformation();

};

#endif // Renderer_h__

