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

	return 0;
}
