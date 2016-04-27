#include "Application_Manager/ApplicationManager.h"

int main(void)
{
	//Specify OpenGL version as 3.3
    int openGL_major_version = 3;
    int openGL_minor_version = 3;

	//Unique object for the application manager
    std::unique_ptr<ApplicationManager> app_manager (new ApplicationManager(openGL_major_version,openGL_major_version));
	
	// Initialize the window providing its width and height
    if(app_manager->initalize_application(1280, 720) == true)
	{
        app_manager->start_main_loop();
        app_manager->close_application();
	}
}
