#include "Engine.h"
#include <iostream>
#include <windows.h>
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
		//시계의 정밀도
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);

		//프레임 계산용 변수
		int64_t currentTime = 0;
		int64_t previousTime = 0;

		//하드웨어 타이머로 시간 구하기
		LARGE_INTEGER time;
		QueryPerformanceCounter(&time);

		currentTime = time.QuadPart;
		previousTime = currentTime;

		//기준 프레임
		float targetFrameRate = 120.0f;
		float oneFrameTime = 1.0f / targetFrameRate;
		// 엔진 루프(게임 루프)
		// 
		while (!isQuit)
		{
			//현재시간 구하기
			QueryPerformanceCounter(&time);
			currentTime = time.QuadPart;

			//시계의 정밀도
			

			// 프레임 시간 계산
			float deltaTime
				= static_cast<float>(currentTime - previousTime);

			//초단위 변환
			deltaTime = deltaTime
				/ static_cast<float>(frequency.QuadPart);
			
			if (deltaTime >= oneFrameTime)
			{
				ProcessInput();

				//프레임 처리
				Tick(deltaTime);
				Draw();
			}

			ProcessInput();

			//프레임 처리
			Tick(deltaTime);
			Draw();

			//이전 시간 값 갱신
			previousTime = currentTime;
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