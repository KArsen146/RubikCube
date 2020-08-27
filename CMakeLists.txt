cmake_minimum_required(VERSION 3.14)
project(proga8_Rubik_s_cube)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${GLUT_INCLUDE_DIR})
include_directories(${OpenGL_INCLUDE_DIRS})

add_executable(proga8_Rubik_s_cube main.cpp brink.h cube_sweep.cpp cube_sweep.h small_cube.h cube.h)
target_link_libraries(proga8_Rubik_s_cube ${OpenGL_LIBRARIES})
target_link_libraries(proga8_Rubik_s_cube ${GLUT_LIBRARIES})