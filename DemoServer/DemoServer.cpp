#include <future>
#include <iostream>

#include "DemoServer.h"
#include <string>
#include "baseMessage.h"
#include "StatusMesseage.h"
#include "DiscoverMessege.h"
#include <fstream>
#include <sstream>
#pragma comment(lib,"Ws2_32.lib")
using namespace std;

int main()
{
	WSADATA wsa_data;
	SOCKADDR_IN server_addr, client_addr;

	WSAStartup(MAKEWORD(2, 2), &wsa_data);
	const auto server = socket(AF_INET, SOCK_STREAM, 0);

	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5555);

	::bind(server, reinterpret_cast<SOCKADDR*>(&server_addr), sizeof(server_addr));
	listen(server, 0);

	std::cout << "Listening for incoming connections..." << endl;

	int client_addr_size = sizeof(client_addr);

	for (;;)
	{
		SOCKET client;

		if ((client = accept(server, reinterpret_cast<SOCKADDR*>(&client_addr), &client_addr_size)) != INVALID_SOCKET)
		{
			auto fut = async(launch::async, on_client_connect, client);
		}

		const auto last_error = WSAGetLastError();

		if (last_error > 0)
		{
			std::cout << "Error: " << last_error << endl;
		}
	}
}

void on_client_connect(SOCKET client)
{
	char buffer[1024];
	ofstream  myfile;
	std::string messege = "";
	std::cout << "Client connected!" << endl;
	while (true)
	{
		recv(client, buffer, sizeof(buffer), 0);
		baseMessage* baseMessage_=NULL;
		if (buffer[0] == '&' && buffer[2] == '&')
		{
			std::stringstream name;
			name << "camera_" << buffer[1] << ".txt";

			myfile = (ofstream)(name.str().c_str());

		}
		else
			if (buffer[0] == '#') {
				for (int i = 1; buffer[i] != '#'; i++)
				{
					messege += buffer[i];
				}
				if (messege.length() == 14)
				{
					baseMessage_ = new DiscoverMessege((unsigned char*)messege.c_str());
					baseMessage_->parseMessage();
					myfile << ((DiscoverMessege*)(baseMessage_))->toString();

				}
				else {
					baseMessage_ = new StatusMesseage((unsigned char*)messege.c_str());
					baseMessage_->parseMessage();
					myfile << ((StatusMesseage*)(baseMessage_))->toString();
				}
				delete baseMessage_;

			}
			else if(buffer[0]=='E') {
				myfile.close();
			}
		std::cout << "Client says: " << buffer << endl;
		memset(buffer, 0, sizeof(buffer));
	}
	closesocket(client);
	std::cout << "Client disconnected." << endl;
}