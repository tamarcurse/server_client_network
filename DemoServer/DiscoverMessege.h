#pragma once
#include "baseMessage.h"
#include <sstream>
class DiscoverMessege :
    public baseMessage
{
protected:
    float distance;// (500 - 10000)
    float angle;// (0 - 360)
    float speed;// (0 - 1000)
public:
    DiscoverMessege();
    DiscoverMessege(int messageId, int messageType, float distanc, float angle, float speed);
    ~DiscoverMessege();
    void parseMessage();
    void parseBack();
    void print();
    unsigned char* getMessageBuffer();
    DiscoverMessege(unsigned char* messageBuffer);
    std::string DiscoverMessege::toString();
};

