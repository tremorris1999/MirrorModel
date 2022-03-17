#include "mirrormod.h"
#include <vector>

using namespace mirrormod;
int main(void)
{
	std::vector<mesh_t> meshes;

	if (!parseObj("test.obj", meshes))
		return -1;

	std::vector<float> first_position = { 1.0f, -1.0f, -0.0f };
	std::vector<float> last_position = { -1.0f, 1.0f, 0.0f };
	std::vector<float> first_uv = { 1.0f, 0.0f };
	std::vector<float> last_uv = { 0.0f, 1.0f };
	std::vector<float> normal = { -0.0f, -0.0f, 1.0f };

	mesh_t mesh = meshes[0];
	vertex_t first_vertex = mesh.vertices[0];
	vertex_t last_vertex = mesh.vertices[mesh.vertices.size() - 1];

	for (int i = 0; i < 3; i++)
	{
		if (first_vertex.position[i] != first_position[i] || last_vertex.position[i] != last_position[i])
			return -1;

		if (first_vertex.normal[i] != normal[i] || last_vertex.normal[i] != normal[i])
			return -1;

		if (i < 2)
			if (first_vertex.uv[i] != first_uv[i] || last_vertex.uv[i] != last_uv[i])
				return -1;
	}

	return 0;
}
