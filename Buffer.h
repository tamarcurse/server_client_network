#pragma once
#include "baseMessage.h"
#include <mutex>
#include <thread>
class Buffer
{
protected:
	unsigned char** buffer;
	int count;
	std::mutex m;

public:
	void AddToBuffer(unsigned char* newMessege);
	unsigned char** GetBuffer();
	
	void CleanBuffer();
	bool IsEmptay();
	Buffer();
	~Buffer();

};

