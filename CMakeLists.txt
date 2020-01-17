cmake_minimum_required(VERSION 3.8.2)
project(OpenGL)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(CMAKE_FRAMEWORK_PATH "~/.brew/Cellar/")
set(SOURCE src/)
set(INCLUDE include/)

find_package(GLUT)
set(GLEW_INCLUDE_DIR "/Users/ggavryly/.brew/Cellar/glew/2.1.0/include/GL/")
set(GLEW_LIBRARIES "/Users/ggavryly/.brew/Cellar/glew/2.1.0/lib/libGLEW.dylib")
set(GLFW_INCLUDE_DIR "/Users/ggavryly/.brew/Cellar/glfw/3.3/include/GLFW/")
set(GLFW_LIBRARIES "/Users/ggavryly/.brew/Cellar/glfw/3.3/lib/")
set(FREETYPE_INCLUDE_DIR "/Users/ggavryly/.brew/Cellar/freetype/2.10.1/include/freetype2/freetype/")
set(FREETYPE_INCLUDE_DIR0 "/Users/ggavryly/.brew/Cellar/freetype/2.10.1/include/freetype2/")
set(FREETYPE_LIBRARIES "/Users/ggavryly/.brew/Cellar/freetype/2.10.1/lib/libfreetype.dylib")
set(GLM_INCLUDE_DIR "/Users/ggavryly/.brew/Cellar/glm/0.9.9.5/include/glm/")
set(SOIL_INCLDE_DIR "/Users/ggavryly/CLionProjects/OpenGL/SOIL/src/")
set(SOIL_LIBRARY "/Users/ggavryly/CLionProjects/OpenGL/SOIL/libSOIL.a")
include_directories(${GLEW_INCLUDE_DIR})
include_directories(${GLUT_INCLUDE_DIR})
include_directories(${GLFW_INCLUDE_DIR})
include_directories(${FREETYPE_INCLUDE_DIR})
include_directories(${FREETYPE_INCLUDE_DIR0})
include_directories(${GLM_INCLUDE_DIR})
include_directories(${SOIL_INCLDE_DIR})

include_directories(
        ${SOURCE}
        ${INCLUDE})

link_directories(
        ${SOURCE}
        ${INCLUDE})
link_directories(${GLFW_LIBRARIES})
#link_directories(${SOIL_LIBRARY})

file(GLOB all
        "${INCLUDE}*.hpp"
        "${SOURCE}*.cpp")

add_executable(${PROJECT_NAME} ${all} src/Shader.cpp include/Shader.hpp src/Texture.cpp include/Texture.hpp src/Menu.cpp include/Menu.hpp)

target_link_libraries(${PROJECT_NAME} "-framework Cocoa" -lglfw ${FREETYPE_LIBRARIES} ${GLEW_LIBRARIES} ${GLUT_LIBRARIES} ${SOIL_LIBRARY})