#include "src\graphic\window.h"
#include "src\input\input.h"

using namespace core;
using namespace graphic;
using namespace input;

int main()
{
	Window window("GLEngine", 960, 540);
	glClearColor(0.2f, 0.3f, 0.5f, 1.0f);

	while (!window.closed())
	{
		window.mainLoop();
	}

	return 0;
}