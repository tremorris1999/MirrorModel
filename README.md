# MirrorModel
[![CMake](https://github.com/tremorris1999/MirrorModel/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/tremorris1999/MirrorModel/actions/workflows/cmake.yml)
### A *(hopefully)* cross-platform C++ Model loading library.
Intended for use in my personal project [tremorris1999](https://github.com/tremorris1999)/[Mirror](https://github.com/tremorris1999/Mirror), but feel free to use/contribute if it suits you.  

# Supported file types:
**Note:** this may be an ever-evolving list.
- [x] [Wavefront](https://en.wikipedia.org/wiki/Wavefront_.obj_file) (.obj) *
- [ ] [glTF](https://www.khronos.org/gltf/)

 \* Missing support for lines, parameter space geometry, vertex groups, smoothing groups, relative indices (unlikely to be added), and MTL.  

# Tested Platforms:
**Note:** These are only the platforms I *currently* have personal access to without setting up new testing environments. Feel free to test your platform and have me add it to the list!
- [ ] Windows 10
- [ ] Fedora 35

# API
Currently, I'm taking an approach focused entirely on integrating into my personal project. Thus the parser(s) have only one standardized output type (for now): *mesh_t*.

*mesh_t:*
```cpp
struct mesh_t
{
	std::vector<float> vertices;
	std::vector<float> normals;
	std::vector<float> textures;
	std::vector<unsigned int> indices;
};
```

I've opted to not use [OpenGL Mathematics](https://github.com/g-truc/glm) (GLM) for now in order to reduce external dependencies. I may add another type that utilizes GLM in the future.
