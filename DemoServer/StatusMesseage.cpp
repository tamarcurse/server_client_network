#include "StatusMesseage.h"
#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <sstream>
void StatusMesseage::parseMessage()
{

	if (this->messageBuffer == NULL)
		return;

	std::memcpy(&(this->messageType), this->messageBuffer, 2);
	std::memcpy(&(this->status), (messageBuffer + 2), 1);
}

void StatusMesseage::parseBack()
{
	this->messageBuffer = (unsigned char*)malloc(3);
	std::memcpy(this->messageBuffer, &(this->messageType), 2);
	std::memcpy((messageBuffer + 2), &(this->status), 1);
}

StatusMesseage::StatusMesseage(int messageId, int messageType, short status) :baseMessage(messageId, messageType)
{

	if (status < 1 || status>3)
		this->status = 0;
	else
		this->status = status;
}

StatusMesseage::StatusMesseage()
{
}

void StatusMesseage::print()
{
	std::cout << "type: " << this->messageType << "\t" << "status: " << this->status << "\n";
}
unsigned char* StatusMesseage::getMessageBuffer()
{
	return messageBuffer;
}
std::string StatusMesseage::toString()
{
	std::string res = "messegeId : " + messageId;
	res += "\tmessageType: " + messageId;
	res += " status: " + status;

	return res;
}
StatusMesseage::StatusMesseage(unsigned char* messageBuffer) :baseMessage(messageBuffer)
{
}
