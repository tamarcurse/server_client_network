#include "Configur.h"

Configur::Configur(std::string srcFile)
{
	std::ifstream file(srcFile);
	if (file.is_open())
	{


		//std::istringstream is_file(srcFile);

		std::string line;
		while (getline(file, line))
		{
			std::istringstream is_line(line);
			std::string key;
			if (std::getline(is_line, key, '='))
			{
				std::string value;
				if (std::getline(is_line, value))
					InsertData(key, value);
			}
		}
		file.close();
	}
}
Configur::Configur()
{
}
void Configur::InsertData(std::string key, std::string value) {
	if (key == "num_of_camera")
	{
		num_of_camera = stoi(value);
		return;
	}
	if (key == "num_of_image_to_second") {
		num_of_image_to_second = stoi(value);
		return;
	}
	if (key == "ip_sever")
	{
		ip_sever = value;
		return;
	}
	if (key == "port_sever")
	{
		port_sever = stoi(value);

	}
}

int Configur::getPort_sever()
{
	return port_sever;
}

int Configur::get_num_of_image_to_second()
{
	return num_of_image_to_second;
}

std::string Configur::getIp_sever()
{
	return ip_sever;
}

int Configur::getNum_of_camera()
{
	return num_of_camera;
}
