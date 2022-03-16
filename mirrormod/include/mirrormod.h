#pragma once
#include <string>
#include <vector>

namespace mirrormod
{
	struct vertex_t
	{
		std::vector<float> position;
		std::vector<float> uv;
		std::vector<float> normal;
	};

	struct mesh_t
	{
		std::vector<vertex_t> vertices;
	};

	bool writeMir(std::string path, std::vector<mesh_t> &meshes);

	bool parseMir(std::string path, std::vector<mesh_t> &meshes);
	bool parseObj(std::string path, std::vector<mesh_t> &meshes);
}