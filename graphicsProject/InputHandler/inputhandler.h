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
#include "../actions.h"

class InputHandler
{
    static InputHandler* m_pInstance;
    static int KeyPressed; //Keep the code of the pressed key
    static int KeyState; // keep the code that tells whether the key was pressed, released of repeated
    static double MouseXPos; //Keep the x-value of the mouse position
    static double MouseYPos; //Keep the y-value of the mouse position
    Actions actions;

    Renderer* mRenderer;
    GLFWwindow* mWindow;

    static void _on_key_event(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void MouseMoved(GLFWwindow* window, double xpos, double ypos);

    InputHandler(Renderer* mRenderer, GLFWwindow* mWindow);

public:
    static InputHandler* instance(Renderer* mRenderer, GLFWwindow* mWindow);
    static InputHandler* instance();
    void handle_key_press();
    void handle_key_release();
    bool is_key_pressed(int key);
    Actions handle_keyboard_input();
    void HandleMouseInput();
};

#endif // INPUTHANDLER_H
