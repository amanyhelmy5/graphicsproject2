#include "inputhandler.h"

InputHandler* InputHandler::m_pInstance = NULL;

int InputHandler::KeyPressed = -1;
int InputHandler::KeyState = -1;
double InputHandler::MouseXPos = -1.0;
double InputHandler::MouseYPos = -1.0;

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

InputHandler::InputHandler(Renderer* mRenderer, GLFWwindow* mWindow)
{
    this->mRenderer = mRenderer;
    this->mWindow = mWindow;

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(mWindow, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetKeyCallback(mWindow, &this->_on_key_event);

    //initialize a value for the mouse position.
    MouseXPos = ApplicationManager::WindowSizeWidth/2;
    MouseYPos = ApplicationManager::WindowSizeHeight/2;
    glfwSetCursorPos(mWindow,MouseXPos,MouseYPos);
    glfwSetCursorPosCallback(mWindow, &this->MouseMoved);
}

// Keyboard pressing event
void InputHandler::_on_key_event(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    InputHandler* input = InputHandler::instance();
    if(!input)
        exit(1);
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        InputHandler::KeyPressed = key;
        input->handle_key_press();
    }
    if(action == GLFW_RELEASE)
    {
        InputHandler::KeyPressed = key;
        input->handle_key_release();
    }
}

Actions InputHandler::handle_keyboard_input()
{
    handle_key_press();
    return this->actions;
}

void InputHandler::handle_key_press()
{
    if (InputHandler::KeyPressed != -1)
    {
        if (InputHandler::KeyPressed == GLFW_KEY_UP || InputHandler::KeyPressed == GLFW_KEY_W)
            actions.forwards = true;
        else if (InputHandler::KeyPressed == GLFW_KEY_DOWN || InputHandler::KeyPressed == GLFW_KEY_S)
            actions.backwards = true;
        if (InputHandler::KeyPressed == GLFW_KEY_RIGHT || InputHandler::KeyPressed == GLFW_KEY_D)
            actions.right = true;
        else if (InputHandler::KeyPressed == GLFW_KEY_LEFT || InputHandler::KeyPressed == GLFW_KEY_A)
            actions.left = true;
        if (InputHandler::KeyPressed == GLFW_KEY_SPACE)
            actions.jump = true;
        if (InputHandler::KeyPressed == GLFW_KEY_LEFT_CONTROL)
            actions.fall = true;
        InputHandler::KeyPressed = -1;
    }
}

void InputHandler::handle_key_release()
{
    if (InputHandler::KeyPressed != -1)
    {
        if (InputHandler::KeyPressed == GLFW_KEY_UP || InputHandler::KeyPressed == GLFW_KEY_W)
            actions.forwards = false;
        else if (InputHandler::KeyPressed == GLFW_KEY_DOWN || InputHandler::KeyPressed == GLFW_KEY_S)
            actions.backwards = false;
        if (InputHandler::KeyPressed == GLFW_KEY_RIGHT || InputHandler::KeyPressed == GLFW_KEY_D)
            actions.right = false;
        else if (InputHandler::KeyPressed == GLFW_KEY_LEFT || InputHandler::KeyPressed == GLFW_KEY_A)
            actions.left = false;
        if (InputHandler::KeyPressed == GLFW_KEY_SPACE)
            actions.jump = false;
        if (InputHandler::KeyPressed == GLFW_KEY_LEFT_CONTROL)
            actions.fall = false;
        InputHandler::KeyPressed = -1;
    }
    //mRenderer->HandleKeyboardInput(actions);
}

bool InputHandler::is_key_pressed(int key)
{
    return (glfwGetKey(mWindow, key ) == GLFW_PRESS) ? true : false;
}

// Mouse movement event
void InputHandler::MouseMoved(GLFWwindow* window, double xpos, double ypos)
{
    InputHandler* input = InputHandler::instance();
    if(!input)
        exit(1);
    //set the new mouse position to the MousXPos and MousYPos
     InputHandler::MouseXPos = xpos;
     InputHandler::MouseYPos = ypos;
     input->HandleMouseInput();
}

void InputHandler::HandleMouseInput()
{
    // check if a mouse moved
    if (InputHandler::MouseXPos != ApplicationManager::WindowSizeWidth/2
     || InputHandler::MouseYPos != ApplicationManager::WindowSizeHeight/2)
    {
        double mouseSpeed = 0.005; //it is just there to speed up or slow down the movements.
        double movedDistanceX;
        double movedDistanceY;

        //  the distance (old position - new position)
        // in other words:  how far is the mouse from the center of the window ? The bigger this value, the more we want to turn.
        // note that the old position (x_old, y_old) is fixed in this application (x_old = WindoSizeWidth/2, y_old = ApplicationManager::WindowSizeHeight/2)
        movedDistanceX = double(ApplicationManager::WindowSizeWidth/2 - MouseXPos)*mouseSpeed;
        movedDistanceY = double(ApplicationManager::WindowSizeHeight/2 - MouseYPos)*mouseSpeed;

        // Pass the two distances to the Renderer (our drawings)
        mRenderer->HandleMouse( movedDistanceX, movedDistanceY);

        //Force the new position of the mouse to be in the middle of the window
        MouseXPos = ApplicationManager::WindowSizeWidth/2;
        MouseYPos = ApplicationManager::WindowSizeHeight/2;
        glfwSetCursorPos(mWindow,MouseXPos,MouseYPos);
    }
}
