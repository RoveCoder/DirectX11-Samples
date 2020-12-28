#include "Application.h"
#include <SDL.h>
#include <memory>

#ifdef _WIN32
#include <crtdbg.h>
#endif

int main(int argc, char** argv)
{
	// Detect memory leaks on Windows
#if defined _WIN32 &&  defined _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	auto application = std::make_unique<Applicataion>();
	return application->Execute();
}