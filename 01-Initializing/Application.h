#pragma once

#include <SDL_video.h>
#include "Timer.h"

class Applicataion
{
public:
	Applicataion() = default;
	virtual ~Applicataion();

	int Execute();

private:
	// SDL window
	bool SDLInit();
	void SDLCleanup();
	SDL_Window* m_SdlWindow = nullptr;

	// Timer
	Timer m_Timer;
	void CalculateFramesPerSecond();
};