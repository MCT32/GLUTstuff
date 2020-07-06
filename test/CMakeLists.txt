cmake_minimum_required(VERSION 3.10)

# set the project
project(test)

# add the executable
add_executable(test test.cpp)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(test ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
