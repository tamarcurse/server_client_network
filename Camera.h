#pragma once
#include "baseMessage.h"
#include "Buffer.h"
#include "StatusMesseage.h"
#include "DiscoverMessege.h"
#include "Buffer.h"
class Camera
{
protected:
	char cameraId;
	baseMessage** bufferMessege;
	int bufferMessegeIndex;
	Buffer* bufferString;
	bool isActive;
	//static int count;
public:
	Camera(char cameraId);
	~Camera();
	void Generate();
	void SendToBUffer();
	void run();
	void stop();
};

