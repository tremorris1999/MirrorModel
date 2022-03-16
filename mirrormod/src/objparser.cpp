#include "mirrormod.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
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

		std::ifstream fileStream;
		fileStream.open(path);
		if (!fileStream.is_open())
		{
			std::cerr << "Unable to open file: " << path << "  ..." << std::endl;
			return false;
		}

		std::stringstream loadedFileStream;
		loadedFileStream << fileStream.rdbuf();

		std::vector<float> temp_vertices;
		std::vector<float> temp_normals;
		std::vector<float> temp_textures;

		bool first = true;
		mesh_t mesh;

		std::string line;
		while (std::getline(loadedFileStream, line))
		{
			if (line.compare("") == 0)
				continue;

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

				meshes.push_back(mesh);
				break;

			case 1: // v
				temp_vertices.push_back(std::stof(split_line[1]));
				temp_vertices.push_back(std::stof(split_line[2]));
				temp_vertices.push_back(std::stof(split_line[3]));
				break;

			case 2: // vn
				temp_normals.push_back(std::stof(split_line[1]));
				temp_normals.push_back(std::stof(split_line[2]));
				temp_normals.push_back(std::stof(split_line[3]));
				break;

			case 3: // vt
				temp_textures.push_back(std::stof(split_line[1]));
				temp_textures.push_back(std::stof(split_line[2]));
				break;

			case 4: // f
				for (size_t f = 1; f < split_line.size(); f++)
				{
					std::vector<std::string> split_face = split(split_line[f], "/");
					std::vector<float> position;
					std::vector<float> uv;
					std::vector<float> normal;
					size_t v_idx = static_cast<size_t>(std::stoi(split_face[0])) - 1;
					size_t t_idx = -1;
					size_t n_idx = -1;

					if (split_face.size() == 3)
					{
						t_idx = split_face[1].compare("") == 0 ? -1 : static_cast<size_t>(std::stoi(split_face[1])) - 1;
						n_idx = static_cast<size_t>(std::stoi(split_face[2])) - 1;
					}
					else if (split_face.size() == 2)
					{
						t_idx = static_cast<size_t>(std::stoi(split_face[1])) - 1;
					}

					position.push_back(temp_vertices[3 * v_idx]);
					position.push_back(temp_vertices[3 * v_idx + 1]);
					position.push_back(temp_vertices[3 * v_idx + 2]);

					if (t_idx != -1)
					{
						uv.push_back(temp_textures[2 * t_idx]);
						uv.push_back(temp_textures[2 * t_idx + 1]);
					}

					if (n_idx != -1)
					{
						normal.push_back(temp_normals[3 * n_idx]);
						normal.push_back(temp_normals[3 * n_idx + 1]);
						normal.push_back(temp_normals[3 * n_idx + 2]);
					}

					mesh.vertices.push_back(vertex_t{ position, uv, normal });
				}

				break;

			default:
				break;
			}
		}

		meshes.push_back(mesh);
		fileStream.close();
		return true;
	}
}