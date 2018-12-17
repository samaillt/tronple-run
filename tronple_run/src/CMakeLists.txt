cmake_minimum_required(VERSION 2.8)

project(Tromple_run)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

find_package(SDL REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# Pour gérer un bug a la fac, a supprimer sur machine perso:
# set(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)

include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} glimac/include third-party/include project_classes/include)

add_subdirectory(project_classes)
add_subdirectory(glimac)

set(ALL_LIBRARIES project_classes glimac ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})

file(GLOB PROJECT_DIRECTORIES "PROJECT*")

foreach(PROJECT ${PROJECT_DIRECTORIES})
    add_subdirectory(${PROJECT})
endforeach()