# MirrorModel
[![CMake](https://github.com/tremorris1999/MirrorModel/actions/workflows/cmake.yml/badge.svg?branch=main)](https://github.com/tremorris1999/MirrorModel/actions/workflows/cmake.yml)
### A *(hopefully)* cross-platform C++ Model loading library.
Intended for use in my personal project [tremorris1999](https://github.com/tremorris1999)/[Mirror](https://github.com/tremorris1999/Mirror), but feel free to use/contribute if it suits you.  

# Supported file types:
**Note:** this may be an ever-evolving list.
- [x] Custom Mirror Model (.mir)
- [x] [Wavefront](https://en.wikipedia.org/wiki/Wavefront_.obj_file) (.obj) *
- [ ] [glTF](https://www.khronos.org/gltf/)

 \* Missing support for lines, parameter space geometry, vertex groups, smoothing groups, relative indices (unlikely to be added), and MTL.  

# Tested Platforms:
**Note:** These are only the platforms I *currently* have personal access to without setting up new testing environments. Feel free to test your platform and have me add it to the list!
- [x] Windows 10
- [ ] Fedora 35

# API
Currently, I'm taking an approach focused entirely on integrating into my personal project. Thus the parser(s) have only one standardized output type (for now): *mesh_t*, which will utilize the type *vertex_t*.

*mirrormod::mesh_t:*
```cpp
struct mesh_t
{
	std::vector<vertex_t> vertices;
};
```
*mirrormod::vertex_t:*
```cpp
struct vertex_t
{
	std::vector<float> position;
	std::vector<float> uv;
	std::vector<float> normal;
};
```  

I've opted to not use [OpenGL Mathematics](https://github.com/g-truc/glm) (GLM) for now in order to reduce external dependencies. I may add another type that utilizes GLM in the future.
