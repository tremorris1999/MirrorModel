#pragma once
#include <string>
#include <vector>

namespace mirrormod
{
	struct mesh_t
	{
		std::vector<float> position;
		std::vector<float> uv;
		std::vector<float> normal;
	};

	bool writeMir(std::string path, std::vector<mesh_t> &meshes);

	bool parseMir(std::string path, std::vector<mesh_t> &meshes);
	bool parseObj(std::string path, std::vector<mesh_t> &meshes);
}
