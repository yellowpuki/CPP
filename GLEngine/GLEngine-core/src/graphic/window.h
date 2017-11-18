#ifndef WINDOW_H
#define WINDOW_H

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

#define internal static
#define local_persist static
#define global_variable static

namespace core { namespace graphic {

class Window
{
	private:
		const char* name;
		int width;
		int heigth;
		GLFWwindow* window;

	public:
		Window(const char* name, int width, int height);
		~Window();

		bool closed();
		void mainLoop();

	private:
		bool init();
		void update();
		void clear();
		void render();

		friend void resize_callback(GLFWwindow* window, int width, int height);
};

} }
#endif 
/*WINDOW_H*/
