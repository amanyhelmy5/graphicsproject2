#include "inputhandler.h"

InputHandler* InputHandler::m_pInstance = NULL;

int InputHandler::KEY_PRESSED = -1;
int InputHandler::KEY_STATE = -1;
double InputHandler::m_X_mouse_position = -1.0;
double InputHandler::m_Y_mouse_position = -1.0;
int counter1 = 0;
int counter2 = 0;
int counter3 = 0;

// singleton
InputHandler* InputHandler::instance(Renderer *Renderer, GLFWwindow *Window)
{
    if (!InputHandler::m_pInstance)   // Only allow one instance of class to be generated.
           InputHandler::m_pInstance = new InputHandler(Renderer, Window);
    return InputHandler::m_pInstance;
}
InputHandler* InputHandler::instance()
{
    if (!InputHandler::m_pInstance)   // Only allow one instance of class to be generated.
        return NULL;
    return InputHandler::m_pInstance;
}

InputHandler::InputHandler(Renderer* renderer, GLFWwindow* window)
{
    this->m_renderer = renderer;
    this->m_window = window;

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetKeyCallback(window, &this->_on_key_event);

    //initialize a value for the mouse position.
    m_X_mouse_position = ApplicationManager::WINDOW_SIZE_WIDTH/2;
    m_Y_mouse_position = ApplicationManager::WINDOW_SIZE_HEIGHT/2;
    glfwSetCursorPos(window, m_X_mouse_position, m_Y_mouse_position);
    glfwSetCursorPosCallback(window, &this->mouse_moved);
}

// Keyboard pressing event
void InputHandler::_on_key_event(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    InputHandler* input = InputHandler::instance();
    if(!input)
        exit(1);
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        InputHandler::KEY_PRESSED = key;
        input->handle_key_press();
    }
    if(action == GLFW_RELEASE)
    {
        InputHandler::KEY_PRESSED = key;
        input->handle_key_release();
    }
}

Actions InputHandler::handle_keyboard_input()
{
    handle_key_press();
    return this->m_actions;
}

void InputHandler::handle_key_press()
{
    if (InputHandler::KEY_PRESSED != -1)
    {
        if (InputHandler::KEY_PRESSED == GLFW_KEY_UP || InputHandler::KEY_PRESSED == GLFW_KEY_W)
            m_actions.forwards = true;
        else if (InputHandler::KEY_PRESSED == GLFW_KEY_DOWN || InputHandler::KEY_PRESSED == GLFW_KEY_S)
            m_actions.backwards = true;
        if (InputHandler::KEY_PRESSED == GLFW_KEY_RIGHT || InputHandler::KEY_PRESSED == GLFW_KEY_D)
            m_actions.right = true;
        else if (InputHandler::KEY_PRESSED == GLFW_KEY_LEFT || InputHandler::KEY_PRESSED == GLFW_KEY_A)
            m_actions.left = true;
        if (InputHandler::KEY_PRESSED == GLFW_KEY_SPACE)
            m_actions.jump = true;
        if (InputHandler::KEY_PRESSED == GLFW_KEY_LEFT_CONTROL)
            m_actions.fall = true;
        InputHandler::KEY_PRESSED = -1;
    }
}

void InputHandler::handle_key_release()
{
    if (InputHandler::KEY_PRESSED != -1)
    {
        if (InputHandler::KEY_PRESSED == GLFW_KEY_UP || InputHandler::KEY_PRESSED == GLFW_KEY_W)
            m_actions.forwards = false;
        else if (InputHandler::KEY_PRESSED == GLFW_KEY_DOWN || InputHandler::KEY_PRESSED == GLFW_KEY_S)
            m_actions.backwards = false;
        if (InputHandler::KEY_PRESSED == GLFW_KEY_RIGHT || InputHandler::KEY_PRESSED == GLFW_KEY_D)
            m_actions.right = false;
        else if (InputHandler::KEY_PRESSED == GLFW_KEY_LEFT || InputHandler::KEY_PRESSED == GLFW_KEY_A)
            m_actions.left = false;
        if (InputHandler::KEY_PRESSED == GLFW_KEY_SPACE)
            m_actions.jump = false;
        if (InputHandler::KEY_PRESSED == GLFW_KEY_LEFT_CONTROL)
            m_actions.fall = false;
        InputHandler::KEY_PRESSED = -1;
    }
    //mRenderer->HandleKeyboardInput(actions);
}

bool InputHandler::is_key_pressed(int key)
{
    return (glfwGetKey(m_window, key ) == GLFW_PRESS) ? true : false;
}

// Mouse movement event
void InputHandler::mouse_moved(GLFWwindow* window, double xpos, double ypos)
{
    InputHandler* input = InputHandler::instance();
    if(!input)
        exit(1);
    //set the new mouse position to the MousXPos and MousYPos
     InputHandler::m_X_mouse_position = xpos;
     InputHandler::m_Y_mouse_position = ypos;
     input->handle_mouse_input();
}

void InputHandler::handle_mouse_input()
{
    // check if a mouse moved
    if (InputHandler::m_X_mouse_position != ApplicationManager::WINDOW_SIZE_WIDTH/2
     || InputHandler::m_Y_mouse_position != ApplicationManager::WINDOW_SIZE_HEIGHT/2)
    {
        double mouseSpeed = 0.005; //it is just there to speed up or slow down the movements.
        double movedDistanceX;
        double movedDistanceY;

        //  the distance (old position - new position)
        // in other words:  how far is the mouse from the center of the window ? The bigger this value, the more we want to turn.
        // note that the old position (x_old, y_old) is fixed in this application (x_old = WindoSizeWidth/2, y_old = ApplicationManager::WindowSizeHeight/2)
        movedDistanceX = double(ApplicationManager::WINDOW_SIZE_WIDTH/2 - m_X_mouse_position)*mouseSpeed;
        movedDistanceY = double(ApplicationManager::WINDOW_SIZE_HEIGHT/2 - m_Y_mouse_position)*mouseSpeed;

        // Pass the two distances to the Renderer (our drawings)
        m_renderer->update_camera_view( movedDistanceX, movedDistanceY);

        //Force the new position of the mouse to be in the middle of the window
        m_X_mouse_position = ApplicationManager::WINDOW_SIZE_WIDTH/2;
        m_Y_mouse_position = ApplicationManager::WINDOW_SIZE_HEIGHT/2;
        glfwSetCursorPos(m_window,m_X_mouse_position,m_Y_mouse_position);
    }
}
