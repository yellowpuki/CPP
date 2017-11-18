#ifndef INPUT_H
#define INPUT_H

#include "..\graphic\window.h"

#define MAX_KEYS	1024
#define MAX_BUTTONS	35

namespace core { namespace input {

	class Input
	{

	private:
		bool keys[MAX_KEYS];
		bool buttons[MAX_BUTTONS];
		double x, y;

	public:
		Input(GLFWwindow* handle);
		~Input();

		bool isKeyPressed(int keycode);
		bool isButtonPressed(int button);
		void getMousePosition(double& x, double& y);

	private:
		friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void mouse_buttons_callback(GLFWwindow* window, int button, int action, int mods);
		friend void mouse_position_callback(GLFWwindow* window, double xpos, double ypos);
	};

} }
#endif 
/*INPUT_H*/