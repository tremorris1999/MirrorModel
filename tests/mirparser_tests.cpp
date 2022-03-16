#include "mirrormod.h"
#include <vector>

using namespace mirrormod;
int main(void)
{
	std::vector<mesh_t> meshes;
	parseObj("test.obj", meshes);
	writeMir("test.mir", meshes);
	meshes.clear();

	parseMir("test.obj", meshes);

	return 0;
}