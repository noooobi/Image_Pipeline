cmake_minimum_required(VERSION 3.20)

project(image_pipeline
    VERSION 0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(core)
add_subdirectory(stages)
add_subdirectory(io)
add_subdirectory(app)
