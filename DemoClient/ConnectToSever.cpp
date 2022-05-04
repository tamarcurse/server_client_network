#include "ConnectToSever.h"
#include <sstream>
void ConnectToSever::sendMesseToserver(Buffer &buffer, char cameraId)

{
	unsigned char** messege = buffer.GetBuffer();
	stringstream str;
	str << "&" << cameraId << "&";

	send(server, str.str().c_str(), str.str().length(), 0);
	str = (stringstream)"";
	for (int i = 0; i < buffer.GetCount(); i++)
	{

		str << "#" << messege[i] << "#";
		send(server, str.str().c_str(), str.str().length(), 0);
		str = (stringstream)"";
	}
	str << "END";
	send(server, str.str().c_str(), str.str().length(), 0);
	str = (stringstream)"";
}

void ConnectToSever::ConnectToMyServer(const char* ip, int port)
{
	WSAStartup(MAKEWORD(2, 0), &wsa_data);
	 server = socket(AF_INET, SOCK_STREAM, 0);
	
	InetPton(AF_INET, ip, &addr.sin_addr.s_addr);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	connect(server, reinterpret_cast<SOCKADDR*>(&addr), sizeof(addr));
	cout << "Connected to server!" << endl;
}



void ConnectToSever::CloseSocket()
{
	closesocket(server);
	WSACleanup();
	cout << "Socket closed." << endl << endl;
}
