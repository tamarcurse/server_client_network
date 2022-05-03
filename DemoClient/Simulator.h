#pragma once
#include "Camera.h"
#include<stdlib.h>
#include <stdio.h>
#include <thread>
#include <iostream>
#include "Configur.h"
#define MAX_CAMERA 20
class Simulator
{
protected:
	Camera** camerasArray;
	Configur* config;
public:
	Simulator();
	~Simulator();
	void RunCamera();
	void Stop();
};

