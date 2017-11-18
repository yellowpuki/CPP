#include "window.h"
#include "..\input\input.h"

using namespace core;
using namespace input;

namespace core { namespace graphic {

	Window::Window(const char* name, int width, int height)
	{
		this->name		= name;
		this->width		= width;
		this->heigth	= height;

		if(!init())
		{
			glfwTerminate();
		}
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "GLFW is not ok." << std::endl;
			glfwTerminate();
			return false;
		}
		
		window = glfwCreateWindow(width, heigth, name, NULL, NULL);
		Input input(window);

		glfwSetWindowSizeCallback(window, resize_callback);
		glfwSetKeyCallback(window, key_callback);
		glfwSetMouseButtonCallback(window, mouse_buttons_callback);
		glfwSetCursorPosCallback(window, mouse_position_callback);
		glfwMakeContextCurrent(window);

		if (glewInit() != GLEW_OK)
		{
			std::cout << "GLEW is not ok." << std::endl;
			glfwTerminate();
			return false;
		}

		return true;
	}

	void Window::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void Window::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}


	void Window::render()
	{
		glColor3f(1.0f, 0.5f, 0.5f);
		glBegin(GL_QUADS);
		glVertex2f(-0.5f,-0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
	}

	void Window::mainLoop()
	{
		update();
		clear();
		render();
	}

	bool Window::closed()
	{
		return (glfwWindowShouldClose(window) == 1);
	}

	void resize_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}


} }