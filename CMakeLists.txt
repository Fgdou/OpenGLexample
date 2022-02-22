cmake_minimum_required(VERSION 3.21)
project(opengl CXX)

add_subdirectory(lib/glfw)
add_subdirectory(lib/glad)
add_subdirectory(lib/glm)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SRC src/*.cpp src/*.h)

add_executable(opengl lib/stbimage/stb_image.h lib/stbimage/impl.cpp ${SRC})

target_include_directories(opengl PUBLIC lib/glfw/include ${GLAD_INCLUDE_DIRS} lib/stbimage lib/glm/glm)
target_link_libraries(opengl glfw ${GLAD_LIBRARIES} glm)
