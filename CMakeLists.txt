cmake_minimum_required(VERSION 3.10)

project(Mytcp)

add_subdirectory(include)

add_subdirectory(src)

add_executable(Mytcp main.cc)

target_link_libraries(Mytcp PUBLIC MYTCP)

target_link_directories(Mytcp PUBLIC
                      "${PROJECT_BINARY_DIR}"
                      "${PROJECT_SOURCE_DIR}/src"
                      "${PROJECT_SOURCE_DIR}/include"
)