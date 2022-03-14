#include "mirrormod.h"

using namespace mirrormod;
int main(void)
{
	std::vector<mesh_t> meshes;
	parseObj("test.obj", meshes);
	if (!writeMir("test.mir", meshes))
		return -1;

	return 0;
}