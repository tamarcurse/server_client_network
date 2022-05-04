#pragma once
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "Buffer.h"
#pragma comment(lib,"Ws2_32.lib")

using namespace std;
class ConnectToSever
{
private:
	WSADATA wsa_data;
	SOCKADDR_IN addr;
	int port;
	char* ip;
	_In_ SOCKET server;
public:
	void sendMesseToserver(Buffer &buffer,char cameraId);
	void ConnectToMyServer(const char* ip, int port);
	void CloseSocket();
};

