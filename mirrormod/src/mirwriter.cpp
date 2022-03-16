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
		for (mesh_t mesh : meshes)
		{
			fileStream << mesh.vertices.size() << std::endl;
			for (vertex_t vertex : mesh.vertices)
			{
				fileStream << vertex.position.size() << std::endl;
				for (float f : vertex.position)
					fileStream << f << std::endl;
				fileStream << vertex.uv.size() << std::endl;
				for (float f : vertex.uv)
					fileStream << f << std::endl;
				fileStream << vertex.normal.size() << std::endl;
				for (float f : vertex.normal)
					fileStream << f << std::endl;
			}
		}

		fileStream.close();
		return true;
	}
}