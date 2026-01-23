#pragma once

namespace Wanted
{
	//Main game engine class
	class Engine
	{
	public:
		Engine();
		~Engine();

		//engine game roop(game roop)
		void Run();

		void QuitEngine();
	private:
		//입력 처리 함수
		void ProcessInput();

		void Tick(float deltaTime);

		void Draw();


		bool isQuit = false;
	};
}