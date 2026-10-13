cmake_minimum_required(VERSION 3.16)
project(TA1-GRAPHICSPROG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    get_filename_component(COMPILER_BIN_DIR "${CMAKE_CXX_COMPILER}" DIRECTORY)
    get_filename_component(TOOLCHAIN_PREFIX "${COMPILER_BIN_DIR}" DIRECTORY)
    list(PREPEND CMAKE_PREFIX_PATH "${TOOLCHAIN_PREFIX}")
endif()

find_package(GLUT REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME}
        main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        GLUT::GLUT
        OpenGL::GL
)