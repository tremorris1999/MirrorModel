#include "mirrormod.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "nlohmann/json.hpp"

namespace mirrormod
{
    bool parseGLTF(std::string path, std::vector<mesh_t> &meshes)
    {
        std::ifstream fileStream;
        fileStream.open(path);
        if(!fileStream.is_open())
        {
            std::cerr << "Unable to open file: " << path << "  ..." << std::endl;
			return false;
        }

        std::stringstream loadedFileStream;
        loadedFileStream << fileStream.rdbuf();
    }
}