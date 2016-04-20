#include "inputhandler.h"

int InputHandler::KeyPressed = -1;
double InputHandler::MouseXPos = -1.0;
double InputHandler::MouseYPos = -1.0;

InputHandler::InputHandler(Renderer* mRenderer, GLFWwindow* mWindow)
{
    this->mRenderer = mRenderer;
    this->mWindow = mWindow;

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(mWindow, GLFW_STICKY_KEYS, GL_TRUE);
    glfwSetKeyCallback(mWindow, &this->SpecialKeyPressed);

    //initialize a value for the mouse position.
    MouseXPos = ApplicationManager::WindowSizeWidth/2;
    MouseYPos = ApplicationManager::WindowSizeHeight/2;
    glfwSetCursorPos(mWindow,MouseXPos,MouseYPos);
    glfwSetCursorPosCallback(mWindow, &this->MouseMoved);
}

// Keyboard pressing event
void InputHandler::SpecialKeyPressed(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    InputHandler::KeyPressed = key;
}

// Mouse movement event
void InputHandler::MouseMoved(GLFWwindow* window, double xpos, double ypos)
{
    //set the new mouse position to the MousXPos and MousYPos
     InputHandler::MouseXPos = xpos;
     InputHandler::MouseYPos = ypos;
}

void InputHandler::HandleKeyboardInput()
{
    //call the handle keyboard only when a button is pressed.
    if (InputHandler::KeyPressed != -1)
    {
        mRenderer->HandleKeyboardInput(KeyPressed);
        //reset the pressed key.
        KeyPressed = -1;
    }
}

bool InputHandler::is_key_pressed(int key)
{
    return (glfwGetKey(mWindow, key ) == GLFW_PRESS) ? true : false;
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
