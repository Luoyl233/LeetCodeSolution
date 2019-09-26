cmake_minimum_required(VERSION 2.8)

project(Top-100-Liked-Questions)

# define which problem we want to run
add_definitions(-DLEET_CODE=10)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB ALL_SRCS ${PROJECT_SOURCE_DIR}/*/*.cpp)

add_executable(${PROJECT_NAME} ${ALL_SRCS})
