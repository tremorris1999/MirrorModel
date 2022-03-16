#include "mirrormod.h"
#include <iostream>
#include <vector>
#include <fstream>

namespace mirrormod
{
	bool parseMir(std::string path, std::vector<mesh_t> &meshes)
	{
		std::ifstream fileStream;
		fileStream.open(path);
		if (!fileStream.is_open())
		{
			std::cerr << "Failed to open file: " << path << " ..." << std::endl;
			return false;
		}
		
		mesh_t mesh;
		std::vector<float> vertices;
		std::vector<float> normals;
		std::vector<float> textures;

		std::string line;
		std::getline(fileStream, line);
		int num_meshes = 0;//std::stoi(line);
		for (size_t m = 0; m < num_meshes; m++)
		{
			std::getline(fileStream, line);
			int num_vertices = 0;//std::stoi(line);
			for (size_t v = 0; v < num_vertices; v++)
			{
				std::getline(fileStream, line);
				//vertices.push_back(std::stof(line));
			}

			std::getline(fileStream, line);
			int num_textures = std::stoi(line);
			for (size_t vt = 0; vt < num_textures; vt++)
			{
				std::getline(fileStream, line);
				//textures.push_back(std::stof(line));
			}

			std::getline(fileStream, line);
			int num_normals = std::stoi(line);
			for (size_t vn = 0; vn < num_normals; vn++)
			{
				std::getline(fileStream, line);
				//normals.push_back(std::stof(line));
			}

			//mesh.vertices = vertices;
			//mesh.textures = textures;
			//mesh.normals = normals;
			meshes.push_back(mesh);
			vertices.clear();
			textures.clear();
			normals.clear();
		}

		fileStream.close();
		return true;
	}
}