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

class InputHandler;

class ApplicationManager
{
	int mOpenGLMajorVersion;
	int mOpenGLMinorVersion;
	double mTime;
    Actions actions;

    GLFWwindow* mWindow; //Why didn't we use smart pointers here? google it! ;)
	std::unique_ptr<Renderer> mRenderer;
    std::unique_ptr<Game> game;
    std::unique_ptr<InputHandler> mInput_handler;

	void InitializeComponents();
	void Update();
	static void WindowResized(GLFWwindow* window, int width, int height);

public:
    static int WindowSizeWidth;
    static int WindowSizeHeight;

	ApplicationManager(int pOpenGLMajorVersion, int pOpenGLMinorVersion);

	bool InitalizeApplication(int pWindowSizeWidth, int pWindowSizeHeight);
	void StartMainLoop();
	void CloseApplication();

	~ApplicationManager(void);
};
#endif // ApplicationManager_h__

