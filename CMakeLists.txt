cmake_minimum_required (VERSION 3.1)
project (Ping)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}")

file (GLOB_RECURSE SOURCES "GameProgrammingPlayground/*.cpp")
file (GLOB_RECURSE HEADERS "GameProgrammingPlayground/*.h")

set (INCLUDE_DIRS "")
foreach (_headerFile ${HEADERS})
	get_filename_component(_dir ${_headerFile} PATH)
	list (APPEND INCLUDE_DIRS ${_dir})
endforeach ()
list (REMOVE_DUPLICATES INCLUDE_DIRS)

include_directories(${INCLUDE_DIRS})

add_executable(Ping ${SOURCES})

