#include "ApplicationManager.h"

//static members initalization.
int ApplicationManager::WINDOW_SIZE_WIDTH = 0;
int ApplicationManager::WINDOW_SIZE_HEIGHT = 0;

ApplicationManager::ApplicationManager(int openGL_major_version, int openGL_minor_version)
{
    m_openGL_major_version = openGL_major_version;
    m_openGL_minor_version = openGL_minor_version;
}

ApplicationManager::~ApplicationManager(void)
{
    this->close_application();
}

bool ApplicationManager::initalize_application(int window_size_width, int window_size_height)
{
	if( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		return false;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_openGL_major_version); //OpenGL version 3.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_openGL_minor_version); // 3.3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //If requesting an OpenGL version below 3.2, GLFW_OPENGL_ANY_PROFILE

	// Open a window and create its OpenGL context

    m_window = glfwCreateWindow( window_size_width, window_size_width, "My OpenGL Project", NULL, NULL);
    if( m_window == nullptr ){
		fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
		glfwTerminate();
		return false;
	}
    glfwMakeContextCurrent(m_window);
	
	//set the initial time after initalization.
    m_time = glfwGetTime();


	// ******************** Initialize GLEW ******************** //
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		return false;
	}

    glfwSetWindowSizeCallback(m_window, &this->_on_window_resize);
	
    glfwGetWindowSize(m_window, &WINDOW_SIZE_WIDTH, &WINDOW_SIZE_HEIGHT);
	
	//////////////////////////////////////////////////////////////////////////
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it is closer to the camera than the former one
	glDepthFunc(GL_LESS); 
	//////////////////////////////////////////////////////////////////////////

    this->initialize_components(); // To be able to draw

    m_input_handler = std::unique_ptr<InputHandler>( InputHandler::instance(this->m_renderer.get(), this->m_window) );

    m_game = std::unique_ptr<Game>(new Game(m_renderer.get()));
    m_game->initialize();
	return true;
}

void ApplicationManager::initialize_components()
{
	// Rendere will be responsible for all drawings.
    m_renderer =  std::unique_ptr<Renderer>(new Renderer());

	// Initialize primitives/models data (send data to OpenGL buffers)
    m_renderer->initialize();
}

void ApplicationManager::start_main_loop()
{
	bool exitLoop = false;
	do 
	{
		//clear the color buffer, and the depth buffer each frame.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//handle window resize.
	
		//Draw scene.
        m_renderer->draw();
		
		//Update everything every frame (time related).
        this->update();

		// Swap buffers
        glfwSwapBuffers(m_window); //Displaying our finished scene
		glfwPollEvents(); 

        //mInput_handler->HandleMouseInput();
        m_actions = m_input_handler->handle_keyboard_input();
        m_renderer->handle_player_actions(m_actions);

		// Check if the window is closed to terminate
        if ( m_input_handler->is_key_pressed(GLFW_KEY_ESCAPE) || glfwWindowShouldClose(m_window) == true )
        {
            exitLoop = true;
        }

	} while (exitLoop == false);
}

// Terminate the window 
void ApplicationManager::close_application()
{

	glfwTerminate();
    glfwDestroyWindow(m_window);
}

// Window resizing event
void ApplicationManager::_on_window_resize(GLFWwindow* window, int width, int height)
{
    WINDOW_SIZE_WIDTH = width;
    WINDOW_SIZE_HEIGHT = height;
	glViewport(0,0,width,height);
}


void ApplicationManager::update()
{
    float current_time = glfwGetTime(); //get currentTime
    float delta_time = (current_time - m_time); //subtract the previous recorded time (mTime value)* 1000 to convert from nanoseconds to seconds.
    m_time = current_time; //set the mTime with current (for calculating the next frame)

    m_renderer->update(delta_time);
    m_game->update(delta_time);

}
