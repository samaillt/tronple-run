cmake_minimum_required(VERSION 2.8)

project(Tronple_run)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

find_package(SDL REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(SDL_mixer REQUIRED)

# Pour gérer un bug a la fac, a supprimer sur machine perso:
# set(OPENGL_LIBRARIES /usr/lib/x86_64-linux-gnu/libGL.so.1)

include_directories({$SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} ${SDL_MIXER_INCLUDE_DIRS} src/glimac/include src/third-party/include src/project_classes/include)

add_subdirectory(src/project_classes project_classes)
add_subdirectory(src/glimac glimac)

set(ALL_LIBRARIES project_classes glimac ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${SDL_MIXER_LIBRARIES})

add_subdirectory(src/PROJECT PROJECT)

# call the CMakeLists.txt to make the documentation (Doxygen)
# > 'make html' to generate the documentation
# > the documentation is located in : [CMAKE ROOT]/build/doc/doc-doxygen/html
add_subdirectory(doc)