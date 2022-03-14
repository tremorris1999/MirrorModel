#include "mirrormod.h"
#include <vector>

using namespace mirrormod;
int main(void)
{
	std::vector<mesh_t> meshes;
	parseObj("test.obj", meshes);
	writeMir("test.mir", meshes);
	meshes.clear();
	
	if (!parseMir("test.mir", meshes)
		|| meshes[0].vertices.size() != 9
		|| meshes[0].textures.size() != 6
		|| meshes[0].normals.size() != 3
		|| meshes[0].indices.size() != 3)
		return -1;

	return 0;
}