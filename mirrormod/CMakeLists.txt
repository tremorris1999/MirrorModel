# MirrorModel/mirrormod

add_library( mirrormod
	"src/objparser.cpp"
)

target_include_directories( mirrormod PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories( mirrormod PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)