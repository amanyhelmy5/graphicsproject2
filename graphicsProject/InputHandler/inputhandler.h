#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#ifdef __linux__
    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
#elif _WIN32
    #include <Windows.h>
    #include <gl/glew.h>
    #include <gl/glfw3.h>
#endif

#include "../Application_Manager/ApplicationManager.h"
#include "../Renderer/Renderer.h"

class InputHandler
{
    static int KeyPressed; //Keep the code of the pressed key
    static double MouseXPos; //Keep the x-value of the mouse position
    static double MouseYPos; //Keep the y-value of the mouse position


    Renderer* mRenderer;
    GLFWwindow* mWindow;

    static void SpecialKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseMoved(GLFWwindow* window, double xpos, double ypos);
public:
    InputHandler(Renderer* mRenderer, GLFWwindow* mWindow);
    void HandleKeyboardInput();
    void HandleMouseInput();
};

#endif // INPUTHANDLER_H
