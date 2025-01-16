cmake_minimum_required(VERSION 3.14)

# Project Name
project(chessGUI)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add Source Files
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# # Find SDL2 and SDL2_image
# find_package(SDL2 REQUIRED)
# find_package(SDL2_image REQUIRED)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2_IMAGE REQUIRED SDL2_image>=2.0.0)

# Include SDL2 Directories
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# Add Executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Link SDL2 and SDL2_image
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

message(STATUS "SDL2 include directories: ${SDL2_INCLUDE_DIRS}")
message(STATUS "SDL2 libraries: ${SDL2_LIBRARIES}")
message(STATUS "SDL2_image include directories: ${SDL2_IMAGE_INCLUDE_DIRS}")
message(STATUS "SDL2_image libraries: ${SDL2_IMAGE_LIBRARIES}")

