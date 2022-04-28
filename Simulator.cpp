#include "Simulator.h"

Simulator::Simulator()
{
	camerasArray = (Camera**)malloc(sizeof(Camera*) * N);
	for (int i = 0; i < N; i++)
	{
		camerasArray[i] = new Camera(char('a' + i));
	}
	RunCamera();
}

void Simulator::RunCamera()
{
	char input;
	std::thread  threadsGenerate[N];
	std::thread  threadsSend[N];
	for (int i = 0; i < N; i++)
	{
		threadsGenerate[i] = std::thread(&Camera::run, *(camerasArray[i]));
		threadsSend[i] = std::thread(&Camera::SendToServer, *(camerasArray[i]));
		//std::thread Thread(&Camera::run, camerasArray[i]);
		//camerasArray[i]->run();
	}
	
	std::cin >> input;
	for (int i = 0; i < N; i++)
	{
		camerasArray[i]->stop();
		
	}
	/*for (int i = 0; i < N; i++)
	{
		threadsGenerate[i].detach();
		threadsSend[i].detach();

	}*/
	//camerasArray[0]->stop();
	//Stop();
}

void Simulator::Stop()
{
	for (int i = 0; i < N; i++)
	{
		camerasArray[i]->stop();
	}
}
