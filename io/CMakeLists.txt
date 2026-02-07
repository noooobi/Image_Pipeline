find_package(OpenCV REQUIRED)

add_library(io STATIC
    capture/VideoFileSource.cpp
)

target_link_libraries(io
    PUBLIC core
    PRIVATE opencv_videoio opencv_highgui ${OpenCV_LIBS}
)

target_include_directories(io
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
