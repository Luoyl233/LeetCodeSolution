cmake_minimum_required(VERSION 2.8)

project(Weekly-Contest-156)

add_definitions(-DLEET_CODE=1207)

aux_source_directory(. DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})
