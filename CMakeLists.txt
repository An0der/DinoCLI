cmake_minimum_required(VERSION 3.30)
project(DinoCLI VERSION 1.0)

add_executable(main)
target_include_directories(main PUBLIC include)
target_sources(main PUBLIC ${PROJECT_SOURCE_DIR}/src/main.cpp PUBLIC ${PROJECT_SOURCE_DIR}/src/Term.cpp)
