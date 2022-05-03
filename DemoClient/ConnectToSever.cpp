#include "ConnectToSever.h"

void ConnectToSever::sendMesseToserver(Buffer &buffer, char cameraId)

{
	unsigned char** messege = buffer.GetBuffer();
	string str = "&" + cameraId;
	str += "&";
	send(*(_In_ SOCKET*)pserver, str.c_str(), str.length(), 0);

	for (int i = 0; i < buffer.GetCount(); i++)
	{
		str = (char*)messege[i];
		str = "#" + str + "#";
		send(*(_In_ SOCKET*)pserver, str.c_str(), str.length(), 0);
	}
	str = "END";
	send(*(_In_ SOCKET*)pserver, str.c_str(), str.length(), 0);
}

void ConnectToSever::ConnectToMyServer(const char* ip, int port)
{
	WSAStartup(MAKEWORD(2, 0), &wsa_data);
	const auto server = socket(AF_INET, SOCK_STREAM, 0);
	pserver = (void*)&server;
	InetPton(AF_INET, ip, &addr.sin_addr.s_addr);

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	connect(server, reinterpret_cast<SOCKADDR*>(&addr), sizeof(addr));
	cout << "Connected to server!" << endl;
}



void ConnectToSever::CloseSocket()
{
	closesocket(*(_In_ SOCKET*)pserver);
	WSACleanup();
	cout << "Socket closed." << endl << endl;
}
