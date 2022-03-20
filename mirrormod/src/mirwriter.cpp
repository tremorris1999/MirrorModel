#include "mirrormod.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

namespace mirrormod
{
	bool writeMir(std::string path, std::vector<mesh_t> &meshes)
	{
		std::ofstream fileStream;
		fileStream.open(path, std::ofstream::out | std::ofstream::trunc);

		if (!fileStream.is_open())
		{
			std::cerr << "Failed to create/open file: " << path << " ..." << std::endl;
			return false;
		}

		std::stringstream stringStream;

		stringStream << meshes.size() << std::endl;
		
		return true;
	}
}
