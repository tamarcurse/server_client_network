#pragma once
//#include <string.h>
#include <sstream>
#include <fstream>
class Configur
{
	protected:
		int num_of_camera;
		int num_of_image_to_second;
		std::string ip_sever;
		int port_sever;
public:
	Configur(std::string srcFile);
	void InsertData(std::string key, std::string value);
	int getPort_sever();
	int get_num_of_image_to_second();
	std::string getIp_sever();
	int getNum_of_camera();
};

