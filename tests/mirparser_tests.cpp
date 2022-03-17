#include "mirrormod.h"
#include <vector>

using namespace mirrormod;
int main(void)
{
	std::vector<mesh_t> meshes;
	std::vector<mesh_t> mir_meshes;
	parseObj("test.obj", meshes);
	writeMir("test.mir", meshes);

	if (!parseMir("test.mir", mir_meshes))
		return -1;
	
	mesh_t m0 = meshes[0];
	mesh_t m1 = mir_meshes[0];
	if (m0.vertices.size() != m1.vertices.size())
		return -1;

	for (size_t v = 0; v < m0.vertices.size(); v++)
	{
		vertex_t v0 = m0.vertices[v];
		vertex_t v1 = m1.vertices[v];
		if (v0.position.size() != v1.position.size()
			|| v0.uv.size() != v1.uv.size()
			|| v0.normal.size() != v1.normal.size())
			return -1;

		for (size_t p = 0; p < v0.position.size(); p++)
			if (v0.position[p] != v1.position[p])
				return -1;

		for (size_t u = 0; u < v0.uv.size(); u++)
			if (v0.uv[u] != v1.uv[u])
				return -1;

		for (size_t n = 0; n < v0.normal.size(); n++)
			if (v0.normal[n] != v1.normal[n])
				return -1;
	}

	return 0;
}
