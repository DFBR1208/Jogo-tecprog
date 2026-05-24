cmake_minimum_required(VERSION 3.10)

project(Jogo_tecprog)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Jogo_tecprog ${SOURCES})

target_link_libraries(Jogo_tecprog sfml-graphics sfml-window sfml-system)