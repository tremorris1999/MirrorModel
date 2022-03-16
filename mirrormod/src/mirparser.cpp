#include "mirrormod.h"
#include <iostream>
#include <vector>
#include <fstream>

namespace mirrormod
{
	bool parseMir(std::string path, std::vector<mesh_t>& meshes)
	{
		std::ifstream fileStream;
		fileStream.open(path);
		if (!fileStream.is_open())
		{
			std::cerr << "Failed to open file: " << path << " ..." << std::endl;
			return false;
		}

		std::string line;
		std::getline(fileStream, line);

		fileStream.close();
		return true;
	}
}