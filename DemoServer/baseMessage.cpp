#include "baseMessage.h"
#include <stdio.h>
#include <stdlib.h>
unsigned char* baseMessage::getMessageBuffer()
{
	return messageBuffer;
}
baseMessage::baseMessage()
{
}
baseMessage::~baseMessage()
{
	//free(messageBuffer);
}

baseMessage::baseMessage(int messageId, int messageType)
{
	this->messageId = messageId;
	if (messageType == 1 || messageType == 2)
		this->messageType = messageType;
}
baseMessage::baseMessage(unsigned char* messageBuffer)
{
	this->messageBuffer = messageBuffer;
}
