#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Window Dimensions
const GLint HEIGHT = 600, WIDTH = 800;

int main() {
	//Initialize GLFW
	if (!glfwInit())
	{
		printf("GLFW initialisation failed!");
		glfwTerminate();
		return 1;
	}

	//Setup GLFW Window Properties
	//OpenGL Version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Core profile = No Backwards Compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Allow forwards compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Test Window", NULL, NULL);
	if (!mainWindow)
	{
		printf("GLFW Window Create Failed!");
		glfwTerminate();
		return 1;
	}

	//Get Buffer Size Information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//Set context for GLFW to use
	glfwMakeContextCurrent(mainWindow);

	//Allow modern extension features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialisation failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	//Setup Viewport Size
	glViewport(0, 0, bufferWidth, bufferHeight);

	//Loop Until Window Closed
	while (!glfwWindowShouldClose(mainWindow)) {

		//Get + Handle user input events
		glfwPollEvents();

		//Clear Window
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(mainWindow);
	}


	return 0;
}