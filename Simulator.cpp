#include "Simulator.h"

Simulator::Simulator()
{
	config = new Configur("Text.txt");
	camerasArray = (Camera**)malloc(sizeof(Camera*) * config->getNum_of_camera());
	for (int i = 0; i < config->getNum_of_camera(); i++)
	{
		camerasArray[i] = new Camera(char('a' + i),config->get_num_of_image_to_second());
	}
	
	RunCamera();
}

void Simulator::RunCamera()
{
	const int num = config->getNum_of_camera();
	int c = 5;
	char input;
	std::thread threadsGenerate[MAX_CAMERA];
	std::thread threadsSend[MAX_CAMERA];
	//std::thread** threadsGenerate = (std::thread**)malloc(sizeof(std::thread*) * config->getNum_of_camera());
	//std::thread**  threadsSend= (std::thread**)malloc(sizeof(std::thread*) * config->getNum_of_camera());
	for (int i = 0; i < num; i++)
	{
		threadsGenerate[i] = std::thread(&Camera::run, *(camerasArray[i]));
		threadsSend[i] = std::thread(&Camera::SendToServer, *(camerasArray[i]));
		//std::thread Thread(&Camera::run, camerasArray[i]);
		//camerasArray[i]->run();
	}
	
	std::cin >> input;
	for (int i = 0; i < config->getNum_of_camera(); i++)
	{
		camerasArray[i]->stop();
		
	}
	for (int i = 0; i < config->getNum_of_camera(); i++)
	{
		threadsGenerate[i].detach();
		threadsSend[i].detach();

	}
	//camerasArray[0]->stop();
	//Stop();
}

void Simulator::Stop()
{
	for (int i = 0; i < config->getNum_of_camera(); i++)
	{
		camerasArray[i]->stop();
	}
}
