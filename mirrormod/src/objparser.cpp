#include "mirrormod.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

namespace mirrormod
{
	bool parseObj(std::string path, std::vector<mesh_t> &meshes)
	{
		auto split = [](std::string string, std::string delimiter)
		{
			std::vector<std::string> out;
			size_t position = 0;
			std::string token;
			while ((position = string.find(delimiter)) != std::string::npos)
			{
				out.push_back(string.substr(0, position));
				string.erase(0, position + delimiter.length());
			}
			
			out.push_back(string);

			return out;
		};
		auto getCode = [](std::string prefix) // Some .obj definitions not supported yet
		{
			if (prefix.compare("o") == 0)
				return 0;
			else if (prefix.compare("v") == 0)
				return 1;
			else if (prefix.compare("vn") == 0)
				return 2;
			else if (prefix.compare("vt") == 0)
				return 3;
			else if (prefix.compare("f") == 0)
				return 4;
			else
				return -1;
		};

		std::fstream fileStream;
		fileStream.open(path);
		if (!fileStream.is_open())
		{
			std::cerr << "Unable to open file: " << path << "  ..." << std::endl;
			return false;
		}

		bool first = true;
		mesh_t mesh;
		std::vector<float> vertices;
		std::vector<float> normals;
		std::vector<float> textures;
		std::vector<unsigned int> indices;

		std::string line;
		while (std::getline(fileStream, line))
		{
			std::vector<std::string> split_line = split(line, " ");
			std::string prefix = split_line[0];

			switch (getCode(prefix))
			{
			case 0: // new mesh
				if (first)
				{
					first = false;
					break;
				}

				mesh.vertices = vertices;
				mesh.normals = normals;
				mesh.textures = textures;
				mesh.indices = indices;
				meshes.push_back(mesh);

				vertices.clear();
				normals.clear();
				textures.clear();
				indices.clear();
				break;

			case 1: // v
				vertices.push_back(std::stof(split_line[1]));
				vertices.push_back(std::stof(split_line[2]));
				vertices.push_back(std::stof(split_line[3]));
				break;

			case 2: // vn
				normals.push_back(std::stof(split_line[1]));
				normals.push_back(std::stof(split_line[2]));
				normals.push_back(std::stof(split_line[3]));
				break;

			case 3: // vt
				textures.push_back(std::stof(split_line[1]));
				textures.push_back(std::stof(split_line[2]));
				break;

			case 4: // f
				for (size_t i = 1; i < split_line.size(); i++)
				{
					std::vector<std::string> index_split;
					index_split = split(split_line[i], "//");

					if (index_split.size() == 1)
						index_split = split(split_line[i], "/");

					indices.push_back(std::stoi(index_split[0]));
				}
				break;

			default:
				break;
			}
		}

		mesh.vertices = vertices;
		mesh.normals = normals;
		mesh.textures = textures;
		mesh.indices = indices;
		meshes.push_back(mesh);
		return true;
	}
}