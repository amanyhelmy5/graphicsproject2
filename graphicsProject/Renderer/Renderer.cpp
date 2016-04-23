﻿#include "Renderer.h"

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

//	createSquare(mySquare);

//    square6M = glm::translate(0.0f, 0.0f, -500.0f) * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f)                                         * glm::scale(500.0f, 500.0f, 500.0f);
//    square7M = glm::translate(0.0f, 0.0f, 500.0f)  * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f) * glm::rotate(180.0f, 0.0f, 1.0f, 0.0f) * glm::scale(500.0f, 500.0f, 500.0f);
//    square2M = glm::translate(-500.0f, 0.0f, 0.0f) * glm::rotate(90.0f, 0.0f, 1.0f, 0.0f)  * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f) * glm::scale(500.0f, 500.0f, 500.0f);//right
//    square3M = glm::translate(500.0f, 0.0f, 0.0f)  * glm::rotate(90.0f, 0.0f, -1.0f, 0.0f) * glm::rotate(180.0f, 0.0f, 0.0f, 1.0f) * glm::scale(500.0f, 500.0f, 500.0f);//Left
//    square5M = glm::translate(0.0f, -500.0f, 0.0f) * glm::rotate(180.0f, 0.0f, 1.0f, 0.0f) * glm::rotate(90.0f, -1.0f, 0.0f, 0.0f) * glm::scale(500.0f, 500.0f, 500.0f);
//    square4M = glm::translate(0.0f, 100.0f, 0.0f)  * glm::rotate(180.0f, 0.0f, 1.0f, 0.0f) * glm::rotate(90.0f, 1.0f, 0.0f, 0.0f)  * glm::scale(500.0f, 500.0f, 500.0f);


    square = std::unique_ptr<Square> (new Square("uvtemplate.bmp"));
    square->model_matrix = glm::scale(1.0f, 1.0f, 1.0f) * glm::translate(0.0f, 0.0f, 0.0f) * glm::rotate(0.0f, glm::vec3(1.0f, 0.0f, 0.0f));

    /////////////////////////////////////////////////////////////////////////
//	// loading and initalizing textures.
//    mTexture1 = std::unique_ptr<Texture>(new Texture("uvtemplate.bmp",1));
//	//mTexture2 = std::unique_ptr<Texture>(new Texture("bricks.jpg",1));
//	mTexture2 = std::unique_ptr<Texture>(new Texture("right.png", 1));
//	mTexture3= std::unique_ptr<Texture>(new Texture("left.png", 1));
//	mTexture4 = std::unique_ptr<Texture>(new Texture("top.png", 1));
//	mTexture5 = std::unique_ptr<Texture>(new Texture("ground.png", 1));
//	mTexture6 = std::unique_ptr<Texture>(new Texture("back.png", 1));
//	mTexture7 = std::unique_ptr<Texture>(new Texture("front.png", 1));

	//////////////////////////////////////////////////////////////////////////

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



    square->bind_texture();
    glm::mat4 squareMVP =  VP * square->model_matrix;
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &squareMVP[0][0]);
    square->Draw();


	//the floor
	/*
	mTexture2->Bind();
	glm::mat4 floorMVP =  VP * floorM; 
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &floorMVP[0][0]);
	mySquare->Draw();*/

//	mTexture2->Bind();
//	glm::mat4 cubemvp1 = VP * square2M;
//	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &cubemvp1[0][0]);
//	mySquare->Draw();
//	///....

//	mTexture3->Bind();
//	glm::mat4 cubemvp2 = VP * square3M;
//	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &cubemvp2[0][0]);
//	mySquare->Draw();
//	///....

//	mTexture4->Bind();
//	glm::mat4 cubemvp3 = VP * square4M;
//	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &cubemvp3[0][0]);
//	mySquare->Draw();
//	///....

//	mTexture5->Bind();
//	glm::mat4 cubemvp4 = VP * square5M;
//	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &cubemvp4[0][0]);
//	mySquare->Draw();
//	///....

//	mTexture6->Bind();
//	glm::mat4 cubemvp5 = VP * square6M;
//	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &cubemvp5[0][0]);
//	mySquare->Draw();
//	///....

//	mTexture7->Bind();
//	glm::mat4 cubemvp6 = VP * square7M;
//	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &cubemvp6[0][0]);
//	mySquare->Draw();


	
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

	//////////////////////////////////////////////////////////////////////////
	mRenderingModeID = glGetUniformLocation(programID,"RenderingMode");
	//////////////////////////////////////////////////////////////////////////
}

void Renderer::initTransformation()
{
	/////////////////////////////////////////////////////////////////////////////////////////////
	// Transformations
	////////////////////
	// Get a handle for our "MVP" uniform the holder we created in the vertex shader)
	// GLint glGetUniformLocation(GLuint program​, const GLchar *name​);
	// program:  Specifies the program objec(t to be queried.
	// name: Points to a null terminated string containing the name of the uniform variable whose location is to be queried. 
	MatrixID = glGetUniformLocation(programID, "MVP");

	//////////////////////////////////////////////////////////////////////////

	// Projection matrix : 
    myCamera->SetPerspectiveProjection(45.0f,4.0f/3.0f,0.1f,1000.0f);

	// View matrix : 
	myCamera->Reset(0.0,0.0,5.0,
		0,0,0,
		0,1,0);
	//////////////////////////////////////////////////////////////////////////
}

void Renderer::Cleanup()
{
	glDeleteProgram(programID);
}
