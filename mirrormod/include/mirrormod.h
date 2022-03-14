#pragma once
#include <string>
#include <vector>

namespace mirrormod
{
	struct mesh_t
	{
		std::vector<float> vertices;
		std::vector<float> normals;
		std::vector<float> textures;
		std::vector<unsigned int> indices;
	};

	bool writeMir(std::string path, std::vector<mesh_t> &meshes);

	bool parseMir(std::string path, std::vector<mesh_t> &meshes);
	bool parseObj(std::string path, std::vector<mesh_t> &meshes);
}