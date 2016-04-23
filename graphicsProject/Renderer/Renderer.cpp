#include "Renderer.h"

#include <gtc/matrix_transform.hpp> 
#include <gtx/transform.hpp>

Renderer::Renderer()
{

}

Renderer::~Renderer()
{
	Cleanup();
}

void Renderer::Initialize()
{
	myCamera = std::unique_ptr<EulerCamera>(new EulerCamera());

	initShader();

    initTransformation();
}


void Renderer::Update(double deltaTime)
{
	double triangle1RotationSpeed = 0.06;
	double trianglesRotationAngle = triangle1RotationSpeed*deltaTime;
	glm::mat4 rotationMat = glm::rotate((float)trianglesRotationAngle,glm::vec3(0.0,1.0,0.0));
}



void Renderer::Draw()
{		
	// Use our shader
	glUseProgram(programID);

	//send the rendering mode to the shader.
	mRenderingMode = RenderingMode::TEXTURE_ONLY;
	glUniform1i(mRenderingModeID,mRenderingMode);

	// Send our transformation to the currently bound shader, 
	// in the "MVP" uniform
	glm::mat4 VP = myCamera->GetProjectionMatrix() * myCamera->GetViewMatrix();

    glm::mat4 squareMVP;

    //Render all the models
    for (int i = 0; i < models.size(); i++)
    {
        models[i]->bind_texture();
        squareMVP = VP * models[i]->model_matrix;
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &squareMVP[0][0]);
        models[i]->Draw();
    }
}

void Renderer::HandleKeyboardInput(Actions actions)
{
    if (actions.forwards)
        myCamera->Walk(1);

    if (actions.backwards)
        myCamera->Walk(-1);

    if (actions.right)
        myCamera->Strafe(1);

    if (actions.left)
        myCamera->Strafe(-1);

    if (actions.jump)
        myCamera->Fly(1);

    if (actions.fall)
        myCamera->Fly(-1);

	//continue the remaining movements.
	myCamera->UpdateViewMatrix();
}

void Renderer::HandleMouse(double deltaX,double deltaY)
{
	printf("Renderer::MOUSE = %f , %f \n",deltaX,deltaY);

	myCamera->Yaw(deltaX);
	myCamera->Pitch(deltaY);
	myCamera->UpdateViewMatrix();

}


void Renderer::initShader()
{
	// Create and compile our GLSL program from the shaders
	programID = LoadShaders( "SimpleTransformWithColor.vertexshader", "MultiColor.fragmentshader" );

	mRenderingModeID = glGetUniformLocation(programID,"RenderingMode");
}

void Renderer::initTransformation()
{

	MatrixID = glGetUniformLocation(programID, "MVP");

	// Projection matrix : 
    myCamera->SetPerspectiveProjection(45.0f,4.0f/3.0f,0.1f,1000.0f);

	// View matrix : 
	myCamera->Reset(0.0,0.0,5.0,
		0,0,0,
		0,1,0);
}

void Renderer::add_model(std::shared_ptr<Model> model)
{
    models.push_back( model );
}

void Renderer::Cleanup()
{
	glDeleteProgram(programID);
}
