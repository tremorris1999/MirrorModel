# MirrorModel/tests

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/test.obj" "test.obj" COPYONLY)
add_executable( objparser_tests "objparser_tests.cpp" )
add_test( ObjParser objparser_tests )
target_link_libraries( objparser_tests mirrormod )