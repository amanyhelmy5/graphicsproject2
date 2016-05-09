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

    //Render all the models
    for (int i = 0; i < m_models.size(); i++)
    {
        m_models[i]->bind_texture();
        squareMVP = VP * m_models[i]->get_model_matrix();
        glUniformMatrix4fv(m_matrixID, 1, GL_FALSE, &squareMVP[0][0]);
        m_models[i]->draw();
    }
}

void Renderer::handle_player_actions(Actions actions)
{
    if (actions.forwards)
        m_camera->walk(1);

    if (actions.backwards)
        m_camera->walk(-1);

    if (actions.right)
        m_camera->strafe(1);

    if (actions.left)
        m_camera->strafe(-1);

    if (actions.jump)
        m_camera->fly(1);

    if (actions.fall)
        m_camera->fly(-1);

	//continue the remaining movements.
    m_camera->update_view_matrix();
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
}

void Renderer::add_model(std::shared_ptr<Model> model)
{
    m_models.push_back( model );
}

void Renderer::empty_models()
{
    m_models.clear();
}

void Renderer::clean_up()
{
    glDeleteProgram(m_programID);
}
