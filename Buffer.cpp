#include "Buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Buffer::AddToBuffer(unsigned char* newMessege)
{
	m.lock();
	buffer = (unsigned char**)realloc(buffer, sizeof(unsigned char*) * ++count);
	if (buffer == NULL)
	{
		m.unlock();
		exit(1);
	
	}
	/*int len = strlen((char*)newMessege);
	strcpy_s(buffer[count-1])

	buffer[count-1] =(unsigned char*)strdup((char*)newMessege);*/
	buffer[count - 1] = newMessege;
	m.unlock();
}

unsigned char** Buffer::GetBuffer()
{
	return buffer;
}

void Buffer::CleanBuffer()
{
	m.lock();
	for (int i = 0; i < count; i++)
	{
		free(buffer[i]);
	}
	

	free(buffer);
	
	count = 0;
	m.unlock();
}

Buffer::Buffer()
{
	buffer = NULL;
	count = 0;
}

Buffer::~Buffer()
{
	free(buffer);
}
