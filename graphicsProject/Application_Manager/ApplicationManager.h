#ifndef ApplicationManager_h__
#define ApplicationManager_h__
#ifdef __linux__
    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
#elif _WIN32
    #include <Windows.h>
    #include <gl/glew.h>
    #include <gl/glfw3.h>
#endif

#include <memory>
#include "../Renderer/Renderer.h"
#include "../InputHandler/inputhandler.h"
#include "../actions.h"
#include "../game.h"
#include "../Level1.h"
#include "../Level2.h"
class InputHandler;

class ApplicationManager
{
	int current_level = 0;
    int m_openGL_major_version;
    int m_openGL_minor_version;
    Actions m_actions;

    GLFWwindow* m_window; //Why didn't we use smart pointers here? google it! ;)
    std::unique_ptr<Renderer> m_renderer;
	std::vector < std::unique_ptr<Game> > m_levels;
    std::unique_ptr<InputHandler> m_input_handler;

    void initialize_components();
    void update();
    static void _on_window_resize(GLFWwindow* window, int width, int height);

    float m_time;

public:
    static int WINDOW_SIZE_WIDTH;
    static int WINDOW_SIZE_HEIGHT;

    ApplicationManager(int openGL_major_version, int openGL_minor_version);

    bool initalize_application(int window_size_width, int window_size_height);
    void start_main_loop();
    void close_application();

	~ApplicationManager(void);
};
#endif // ApplicationManager_h__

