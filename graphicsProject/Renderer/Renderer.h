#ifndef Renderer_h__
#define Renderer_h__

#ifdef __linux__
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#elif _WIN32
#include <gl/glew.h>
#include <gl/glfw3.h>
#endif

#include <memory>

#include "../Shaders/shader.hpp"
#include "../Texture/texture.h"
#include "../Model/Model.h"
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

	GLuint m_programID;
	GLuint m_matrixID;

	GLuint AmbientLightID;
	GLuint LightPositionID;
	GLuint EyePositionID;
	
	glm::vec3 ambientLight;
	glm::vec3 lightPosition;

	std::vector< std::shared_ptr<Model> > m_models;
	std::unique_ptr<EulerCamera> m_camera;

	GLuint m_rendering_modeID;
	RenderingMode m_rendering_mode;
	GLuint vertexPosition_modelspaceID, inputColorID, texCoordID, vertexNormal_modelspaceID;
	GLuint ModelMatrixID;

	Actions m_actions;


public:
	Renderer();
	~Renderer();

	void initialize();
	void draw();
	void handle_player_actions(Actions);
	void update_camera_view(double deltaX, double deltaY);
	void update(double deltaTime);
	void clean_up();

	void add_model(std::shared_ptr<Model> model);
    void empty_models();

	void initialize_shaders();
    EulerCamera* get_camera();
	void initialize_light();
};

#endif // Renderer_h__

