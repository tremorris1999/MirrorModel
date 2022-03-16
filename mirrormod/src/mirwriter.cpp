#include "mirrormod.h"
#include <vector>
#include <iostream>
#include <fstream>

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

		fileStream << meshes.size() << std::endl;
		for (size_t m = 0; m < meshes.size(); m++)
		{
			mesh_t mesh = meshes[m];

			//fileStream << mesh.vertices.size() << std::endl;
			//for (size_t v = 0; v < mesh.vertices.size(); v++)
			//	fileStream << mesh.vertices[v] << std::endl;

			//fileStream << mesh.textures.size() << std::endl;
			//for (size_t vt = 0; vt < mesh.textures.size(); vt++)
			//	fileStream << mesh.textures[vt] << std::endl;

			//fileStream << mesh.normals.size() << std::endl;
			//for (size_t vn = 0; vn < mesh.normals.size(); vn++)
			//	fileStream << mesh.normals[vn] << std::endl;
		}

		fileStream.close();
		return true;
	}
}