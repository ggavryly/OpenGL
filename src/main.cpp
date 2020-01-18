#include "main.hpp"
#include "Menu.hpp"

int main()
{
	// Init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // for MacOS
	
	GLFWwindow* window = glfwCreateWindow(1024, 768, "LearnOpenGL", nullptr, nullptr); // Windowed
	glfwMakeContextCurrent(window);
	
	// Initialize GLEW to setup the OpenGL Function pointers
	glewExperimental = GL_TRUE;
	glewInit();
	
	// Define the viewport dimensions
	glViewport(0, 0, 1024 * 2, 768 * 2);
	Text text;
	Menu menu;
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check and call events
		glfwPollEvents();
		
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
//		text.displayMessage("123456789012345678901234567890123456789012345678901234567890", Rect(25,25,0,0), glm::vec3(0.5, 0.8f, 0.2f), 1);
		menu.chooseMenu(EM_LoadMenu);
		// Swap the buffers
		glfwSwapBuffers(window);
	}
	
	glfwTerminate();
	return 0;
}