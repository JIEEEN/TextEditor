cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME test)
project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

find_package(spdlog CONFIG REQUIRED)
find_package(SFML COMPONENTS graphics window system REQUIRED)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)


file(GLOB_RECURSE SOURCE_FILE ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADER_FILE ${INCLUDE_DIR}/*.h)


add_executable(${PROJECT_NAME} ${SOURCE_FILE} ${HEADER_FILE})

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)