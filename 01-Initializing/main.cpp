#include "Application.h"
#include <SDL.h>
#include <memory>
#include <crtdbg.h>

int main(int argc, char** argv)
{
	// Detect memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	auto application = std::make_unique<Applicataion>();
	return application->Execute();
}