#pragma once
#include "baseMessage.h"
#include "Buffer.h"
#include "StatusMesseage.h"
#include "DiscoverMessege.h"
#include "Buffer.h"
#include <mutex>
#include <thread>
#include "ConnectToSever.h"
#include "Configur.h"
//#include <mutex>
class Camera
{
protected:
	char cameraId;
	baseMessage** bufferMessege;
	int bufferMessegeIndex;
	Buffer* bufferString;
	bool isActive;
	Configur  config; 
	ConnectToSever server;
	//std::mutex* mutexBuffer;
	//static int count;
public:
	Camera(char cameraId, Configur  &config);
	~Camera();
	void Generate();
	void SendToBUffer();
	void run();
	void stop();
	void SendToServer();
};

