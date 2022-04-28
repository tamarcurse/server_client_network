#pragma once
#include "Camera.h"
#include<stdlib.h>
#include <stdio.h>
#include <thread>
#include <iostream>
#define N 4
class Simulator
{
protected:
	Camera** camerasArray;
public:
	Simulator();
	~Simulator();
	void RunCamera();
	void Stop();
};

