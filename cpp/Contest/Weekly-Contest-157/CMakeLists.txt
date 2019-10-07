cmake_minimum_required(VERSION 2.8)

project(Weekly-Contest-157)

add_definitions(-DLEET_CODE=1217)

aux_source_directory(. DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS})
