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
    static int KEY_PRESSED; //Keep the code of the pressed key
    static int KEY_STATE; // keep the code that tells whether the key was pressed, released of repeated
    static double m_X_mouse_position; //Keep the x-value of the mouse position
    static double m_Y_mouse_position; //Keep the y-value of the mouse position
    Actions m_actions;

    Renderer* m_renderer;
    GLFWwindow* m_window;

    static void _on_key_event(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouse_moved(GLFWwindow* window, double xpos, double ypos);

    InputHandler(Renderer* renderer, GLFWwindow* window);

public:
    static InputHandler* instance(Renderer* m_renderer, GLFWwindow* m_window);
    static InputHandler* instance();
    void handle_key_press();
    void handle_key_release();
    bool is_key_pressed(int key);
    Actions handle_keyboard_input();
    void handle_mouse_input();
};

#endif // INPUTHANDLER_H
