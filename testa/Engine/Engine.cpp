#include "Engine.h"
#include <iostream>

namespace Wanted
{
	Engine::Engine()
	{
		//Constructor
	}
	Engine::~Engine()
	{
		//Destructor
	}
	void Engine::Run()
	{
		// 엔진 루프(게임 루프)
		while (!isQuit)
		{
			ProcessInput();
			Tick(1.0f / 60.0f);
			Draw();
		}

		// Todo: 정리 작업
	}

	void Engine::QuitEngine()
	{
		isQuit = true;
	}


	void Engine::ProcessInput()
	{
	}
	void Engine::Tick(float deltaTime)
	{
		std::cout << "DeltaTime: " << deltaTime
			<< ", FPS: " << 1.0f / deltaTime << std::endl;
	}
	void Engine::Draw()
	{
	}
}