#include "mirrormod.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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

		std::stringstream loadedFileStream;
		loadedFileStream << fileStream.rdbuf();

		std::string line;
		std::getline(loadedFileStream, line);

		int num_meshes = std::stoi(line);
		std::getline(loadedFileStream, line);
		for (size_t m = 0; m < num_meshes; m++)
		{
			mesh_t mesh;
			int num_vertices = std::stoi(line);
			std::getline(loadedFileStream, line);
			for (size_t v = 0; v < num_vertices; v++)
			{
				std::vector<float> positions;
				std::vector<float> uvs;
				std::vector<float> normals;

				int num_positions = std::stoi(line);
				std::getline(loadedFileStream, line);
				for (size_t p = 0; p < num_positions; p++, std::getline(loadedFileStream, line))
					positions.push_back(std::stof(line));

				int num_uvs = std::stoi(line);
				std::getline(loadedFileStream, line);
				for (size_t u = 0; u < num_uvs; u++, std::getline(loadedFileStream, line))
					uvs.push_back(std::stof(line));

				int num_normals = std::stoi(line);
				std::getline(loadedFileStream, line);
				for (size_t n = 0; n < num_normals; n++, std::getline(loadedFileStream, line))
					normals.push_back(std::stof(line));

				mesh.vertices.push_back(vertex_t{ positions, uvs, normals });
			}

			meshes.push_back(mesh);
		}

		fileStream.close();
		return true;
	}
}