#include "mirrormod.h"
#include <vector>
#include <iostream>

using namespace mirrormod;
int main(void)
{
	std::vector<mesh_t> meshes;

	if (!parseObj("test.obj", meshes))
		return -1;

	std::vector<float> expectedPosition
	{
		1, -1, -0,
		-1, 1, 0,
		-1, -1, -0,
		1, -1, -0,
		1, 1, 0,
		-1, 1, 0
	};

	std::vector<float> expectedUV
	{
		1, 0, 0,
		1, 0, 0,
		1, 0, 1,
		1, 0, 1
	};

	std::vector<float> expectedNormal
	{
		-0, -0, 1,
		-0, -0, 1,
		-0, -0, 1,
		-0, -0, 1,
		-0, -0, 1,
		-0, -0, 1
	};

	if (expectedPosition.size() != meshes[0].position.size())
		return -1;
	if (expectedUV.size() != meshes[0].uv.size())
		return -1;
	if (expectedNormal.size() != meshes[0].normal.size())
		return -1;

	for (size_t i = 0; i < expectedPosition.size(); i++)
		if (expectedPosition[i] != meshes[0].position[i])
			return -1;
	for (size_t i = 0; i < expectedUV.size(); i++)
		if (expectedUV[i] != meshes[0].uv[i])
			return -1;
	for (size_t i = 0; i < expectedNormal.size(); i++)
		if (expectedNormal[i] != meshes[0].normal[i])
			return -1;

	return 0;
}
