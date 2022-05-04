#pragma once
#include "baseMessage.h"
#include <sstream>
class StatusMesseage :
    public baseMessage
{
protected:
    short status;//(1-3)
public:
    void parseMessage();
    void parseBack();
    StatusMesseage(int messageId, int messageType, short status);
    StatusMesseage();
   
    void print();
    unsigned char* getMessageBuffer();
    std::string StatusMesseage::toString();
    StatusMesseage(unsigned char* messageBuffer);
};

