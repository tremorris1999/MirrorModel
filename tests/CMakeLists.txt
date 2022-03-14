# MirrorModel/tests

configure_file( "${CMAKE_CURRENT_SOURCE_DIR}/test.obj" "test.obj" COPYONLY)

add_executable( objparser_tests "objparser_tests.cpp" )
add_test( ObjParser objparser_tests )
target_link_libraries( objparser_tests mirrormod )

add_executable( mirwriter_tests "mirwriter_tests.cpp" )
add_test( MirWriter mirwriter_tests )
target_link_libraries( mirwriter_tests mirrormod )

add_executable( mirparser_tests "mirparser_tests.cpp" )
add_test( MirParser mirparser_tests )
target_link_libraries( mirparser_tests mirrormod )