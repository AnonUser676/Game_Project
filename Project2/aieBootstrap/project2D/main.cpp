#include "Application2D.h"
#include <time.h>
#include <windows.h>
#include <crtdbg.h>

int main() 
{
	srand((unsigned int)time(0));
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Application2D* app = new Application2D();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}