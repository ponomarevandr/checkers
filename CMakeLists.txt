cmake_minimum_required(VERSION 3.0)


project(Checkers)

set(SOURCES
	sources/math/geometry.cpp
	sources/math/utilities.cpp
	sources/game/position.cpp
	sources/game/sequential_mover.cpp
	sources/game/game.cpp
	sources/game/machine.cpp
	sources/user/interface.cpp
	sources/user/settings.cpp
)

add_compile_options(-std=c++17 -Wall -Wextra)
include_directories(sources)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(checkers sources/main.cpp ${SOURCES})