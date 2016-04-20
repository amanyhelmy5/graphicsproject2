#include "ApplicationManager.h"

//static members initalization.
int ApplicationManager::WindowSizeWidth = 0;
int ApplicationManager::WindowSizeHeight = 0;

ApplicationManager::ApplicationManager(int pOpenGLMajorVersion, int pOpenGLMinorVersion)
{
	mOpenGLMajorVersion = pOpenGLMajorVersion;
	mOpenGLMinorVersion = pOpenGLMinorVersion;
}

ApplicationManager::~ApplicationManager(void)
{
	this->CloseApplication();
}

bool ApplicationManager::InitalizeApplication(int pWindowSizeWidth, int pWindowSizeHeight)
{
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return false;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, mOpenGLMajorVersion); //OpenGL version 3.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, mOpenGLMinorVersion); // 3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //If requesting an OpenGL version below 3.2, GLFW_OPENGL_ANY_PROFILE

	// Open a window and create its OpenGL context

	mWindow = glfwCreateWindow( pWindowSizeWidth, pWindowSizeWidth, "My OpenGL Project", NULL, NULL);
	if( mWindow == nullptr ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(mWindow);
	
	//set the initial time after initalization.
	mTime = glfwGetTime();


	// ******************** Initialize GLEW ******************** //
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return false;
	}

	glfwSetWindowSizeCallback(mWindow, &this->WindowResized);
	
	glfwGetWindowSize(mWindow,&WindowSizeWidth,&WindowSizeHeight);
	
	//////////////////////////////////////////////////////////////////////////
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it is closer to the camera than the former one
	glDepthFunc(GL_LESS); 
	//////////////////////////////////////////////////////////////////////////

	this->InitializeComponents(); // To be able to draw

    mInput_handler = std::unique_ptr<InputHandler>( InputHandler::instance(this->mRenderer.get(), this->mWindow) );
	return true;
}

void ApplicationManager::InitializeComponents()
{
	// Rendere will be responsible for all drawings.
	mRenderer =  std::unique_ptr<Renderer>(new Renderer());

	// Initialize primitives/models data (send data to OpenGL buffers)
	mRenderer->Initialize();
}

void ApplicationManager::StartMainLoop()
{
	bool exitLoop = false;
	do 
	{
		//clear the color buffer, and the depth buffer each frame.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//handle window resize.
	
		//Draw scene.
		mRenderer->Draw();
		
		//Update everything every frame (time related).
		this->Update();

		// Swap buffers
		glfwSwapBuffers(mWindow); //Displaying our finished scene
		glfwPollEvents(); 

        //mInput_handler->HandleMouseInput();
        actions = mInput_handler->handle_keyboard_input();
        mRenderer->HandleKeyboardInput(actions);

		// Check if the window is closed to terminate
        if ( mInput_handler->is_key_pressed(GLFW_KEY_ESCAPE) || glfwWindowShouldClose(mWindow) == true )
        {
            exitLoop = true;
        }

	} while (exitLoop == false);
}

// Terminate the window 
void ApplicationManager::CloseApplication()
{

	glfwTerminate();
	glfwDestroyWindow(mWindow);
}

// Window resizing event
void ApplicationManager::WindowResized(GLFWwindow* window, int width, int height)
{
	WindowSizeWidth = width;
	WindowSizeHeight = height;
	glViewport(0,0,width,height);
}


void ApplicationManager::Update()
{
	double currentTime = glfwGetTime(); //get currentTime
	double deltaTime = (currentTime - mTime)*1000; //subtract the previous recorded time (mTime value)* 1000 to convert from nanoseconds to seconds.
	mTime = currentTime; //set the mTime with current (for calculating the next frame)

	mRenderer->Update(deltaTime);

}
