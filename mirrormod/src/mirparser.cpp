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
		fileStream.close();

		std::string line;
		std::getline(loadedFileStream, line);

		int num_mesh = std::stoi(line);
		std::getline(loadedFileStream, line);
		for (size_t m = 0; m < num_mesh; m++) 
		{
			std::vector<float> position;
			std::vector<float> uv;
			std::vector<float> normal;

			int num_position = std::stoi(line);
			std::getline(loadedFileStream, line);
			for (int i = 0; i < num_position; i++, std::getline(loadedFileStream, line))
				position.push_back(std::stof(line));

			int num_uv = std::stoi(line);
			std::getline(loadedFileStream, line);
			for (int i = 0; i < num_uv; i++, std::getline(loadedFileStream, line))
				uv.push_back(std::stof(line));

			int num_normal = std::stoi(line);
			std::getline(loadedFileStream, line);
			for (int i = 0; i < num_normal; i++, std::getline(loadedFileStream, line))
				normal.push_back(std::stof(line));

			meshes.push_back(mesh_t{position, uv, normal});
		}

		return true;
	}
}
