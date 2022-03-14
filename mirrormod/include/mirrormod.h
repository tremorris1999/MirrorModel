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

	bool parseObj(std::string path, std::vector<mesh_t> &meshes);
}