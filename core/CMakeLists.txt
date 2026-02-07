find_package(OpenCV REQUIRED)

add_library(core STATIC
    frame/Frame.cpp
)

target_include_directories(core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)


target_include_directories(core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${OpenCV_LIBS} ${OpenCV_INCLUDE_DIRS}
)
