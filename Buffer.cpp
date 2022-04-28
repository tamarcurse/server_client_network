#include "Buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Buffer::AddToBuffer(unsigned char* newMessege)
{
	buffer = (unsigned char**)realloc(buffer, sizeof(unsigned char*) * ++count);
	if (buffer == NULL)
		exit(1);
	/*int len = strlen((char*)newMessege);
	strcpy_s(buffer[count-1])

	buffer[count-1] =(unsigned char*)strdup((char*)newMessege);*/
	buffer[count - 1] = newMessege;
}

unsigned char** Buffer::GetBuffer()
{
	return buffer;
}

void Buffer::CleanBuffer()
{
	/*for (int i = 0; i < count; i++)
	{
		free(buffer[i]);
	}*/
	free(buffer);
	count = 0;
}

Buffer::Buffer()
{
	buffer = NULL;
	count = 0;
}
