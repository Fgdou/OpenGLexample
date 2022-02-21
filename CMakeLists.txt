cmake_minimum_required(VERSION 3.21)
project(opengl)

add_subdirectory(lib/glfw)
add_subdirectory(lib/glad)

set(CMAKE_CXX_STANDARD 14)


add_executable(opengl src/main.cpp src/Program.cpp src/Program.h src/helper.h src/helper.cpp src/VertexBuffer.cpp src/VertexBuffer.h src/IndexBuffer.cpp src/IndexBuffer.h src/BufferDescriptor.cpp src/BufferDescriptor.h)

target_include_directories(opengl PUBLIC lib/glfw/include ${GLAD_INCLUDE_DIRS})
target_link_libraries(opengl glfw ${GLAD_LIBRARIES})
