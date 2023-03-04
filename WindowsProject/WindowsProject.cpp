#include "src/Window/Window.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Window window(hInstance, nCmdShow);
	try
	{
		window.runMessageLoop();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << '\n';
		return EXIT_FAILURE;
	}
	catch (...)
	{
		std::cerr << "Unknown exception caught\n";
		return EXIT_FAILURE;
	}

	return 0;
}
