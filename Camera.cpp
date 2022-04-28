#include "Camera.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

Camera::Camera(char cameraId)
{
	this->cameraId = cameraId;
	//bufferMessege = (baseMessage*)malloc(sizeof(bufferMessege) * N);
	bufferMessege = NULL;
	isActive = true;
	bufferString = new Buffer();
	bufferMessegeIndex = -1;
}

Camera::~Camera()
{
	free(bufferMessege);
	free(bufferString);
}

StatusMesseage* createStatusMessage()
{
	static int id = 0;
	id++;
	return new StatusMesseage(id, 1, rand() % 3 + 1);

}

DiscoverMessege* createDiscoverMessage()
{
	static int id = 99;
	id++;
	return new DiscoverMessege(id, 2, rand() % 9500 + 500, rand() % 361, rand() % 1001);
}

void Camera::Generate()
{
	int count = rand() % 4 + 1;
	for (int i = 0; i < count; i++)
	{
		++bufferMessegeIndex;
		bufferMessege = (baseMessage**)realloc(bufferMessege, sizeof(baseMessage*) * (bufferMessegeIndex + 1));
		(rand() % 2 + 1 == 1) ? bufferMessege[bufferMessegeIndex] = createStatusMessage() : bufferMessege[bufferMessegeIndex] = createDiscoverMessage();
	}


}

void Camera::SendToBUffer()
{
	std::cout << "move from bufferMesage to Buffer string:\n";
	for (int i = 0; i <= bufferMessegeIndex; i++)
	{
		bufferMessege[i]->parseBack();
		bufferString->AddToBuffer(bufferMessege[i]->getMessageBuffer());
		//bufferMessege[i]->~baseMessage();
		bufferMessege[i]->print();
		free(bufferMessege[i]);
	}
	bufferMessegeIndex = -1;
	free(bufferMessege);
	bufferMessege = NULL;
}

void Camera::run()
{
	while (isActive)
	{
		Generate();
		SendToBUffer();
	}
}

void Camera::stop()
{
	isActive = false;
}
