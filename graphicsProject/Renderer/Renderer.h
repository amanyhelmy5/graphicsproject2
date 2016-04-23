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

	std::unique_ptr<Model> myTriangle;
	std::unique_ptr<Model> mySquare;


	std::unique_ptr<EulerCamera> myCamera;


	GLuint mRenderingModeID;
	RenderingMode mRenderingMode;


    std::unique_ptr<Square> square;
	glm::mat4 squareM;

	glm::mat4 floorM;
	glm::mat4 square7M;
	glm::mat4 square2M;
	glm::mat4 square3M;
	glm::mat4 square4M;
	glm::mat4 square5M;
	glm::mat4 square6M;

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

	void initShader();
	void initTransformation();

};

#endif // Renderer_h__

