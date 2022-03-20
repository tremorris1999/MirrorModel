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
		for (mesh_t mesh : meshes)
		{
			stringStream << mesh.position.size() << std::endl;
			for (float f : mesh.position)
				stringStream << f << std::endl;

			stringStream << mesh.uv.size() << std::endl;
			for (float f : mesh.uv)
				stringStream << f << std::endl;

			stringStream << mesh.normal.size() << std::endl;
			for (float f : mesh.normal)
				stringStream << f << std::endl;
		}

		fileStream << stringStream.rdbuf();
		fileStream.close();

		return true;
	}
}
