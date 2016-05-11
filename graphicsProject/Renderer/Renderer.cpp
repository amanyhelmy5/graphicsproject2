#include "Renderer.h"

#include <gtc/matrix_transform.hpp> 
#include <gtx/transform.hpp>

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
    clean_up();
}

void Renderer::initialize()
{
	m_camera = std::unique_ptr<EulerCamera>(new EulerCamera());

    initialize_shaders();

    m_matrixID = glGetUniformLocation(m_programID, "MVP");

	initialize_light();
}


void Renderer::update(double deltaTime)
{

}



void Renderer::draw()
{		
	// Use our shader
    glUseProgram(m_programID);

	//send the rendering mode to the shader.
	m_rendering_mode = RenderingMode::TEXTURE_ONLY;
    glUniform1i(m_rendering_modeID, m_rendering_mode);

	// Send our transformation to the currently bound shader, 
	// in the "MVP" uniform
    glm::mat4 VP = m_camera->get_projection_matrix() * m_camera->get_view_matrix();

    glm::mat4 squareMVP;
	glm::mat4 modelm;
    //Render all the models
    for (int i = 0; i < m_models.size(); i++)
    {
        m_models[i]->bind_texture();
        squareMVP = VP * m_models[i]->get_model_matrix();
		modelm = m_models[i]->get_model_matrix();
        glUniformMatrix4fv(m_matrixID, 1, GL_FALSE, &squareMVP[0][0]);
		glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &modelm[0][0]);
		m_models[i]->draw(vertexPosition_modelspaceID, inputColorID, texCoordID, vertexNormal_modelspaceID);
		

    }

    m_camera->update_view_matrix();
}

void Renderer::handle_player_actions(Actions actions)
{


	//continue the remaining movements.

}

void Renderer::update_camera_view(double delta_X,double delta_Y)
{
    m_camera->yaw(delta_X);
    m_camera->pitch(delta_Y);
    m_camera->update_view_matrix();
}


void Renderer::initialize_shaders()
{
	// Create and compile our GLSL program from the shaders
    m_programID = LoadShaders( "SimpleTransformWithColor.vertexshader", "MultiColor.fragmentshader" );

    m_rendering_modeID = glGetUniformLocation(m_programID,"RenderingMode");
	vertexNormal_modelspaceID = glGetAttribLocation(m_programID, "vertexNormal_modelspace");

	ModelMatrixID = glGetUniformLocation(m_programID, "ModelMatrix");

	inputColorID = glGetAttribLocation(m_programID, "inputColor");

	texCoordID = glGetAttribLocation(m_programID, "texCoord");

}

void Renderer::add_model(std::shared_ptr<Model> model)
{
    m_models.push_back( model );
}

void Renderer::empty_models()
{
    m_models.clear();
}

EulerCamera* Renderer::get_camera()
{
    return m_camera.get();
}

void Renderer::clean_up()
{
    glDeleteProgram(m_programID);
}
void  Renderer::initialize_light()
{
	// Configure the light.
	LightPositionID = glGetUniformLocation(m_programID, "LightPosition_worldspace");
	lightPosition = glm::vec3(1.0, 0.25, 0.0);
	glUniform3fv(LightPositionID, 1, &lightPosition[0]);
	//setup the ambient light component.
	AmbientLightID = glGetUniformLocation(m_programID, "ambientLight");
	ambientLight = glm::vec3(0.1, 0.1, 0.1);
	glUniform3fv(AmbientLightID, 1, &ambientLight[0]);
	//setup the eye position.
	EyePositionID = glGetUniformLocation(m_programID, "EyePosition_worldspace");
	glUniform3fv(EyePositionID, 1, &(m_camera->GetEyePosition()[0]));
//glUniform3fv(EyePositionID, 1,->GetEyePosition()[0]);

}