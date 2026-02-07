find_package(OpenCV REQUIRED)

add_library(stages STATIC
    GrayscaleStage.cpp
    Pipeline.cpp
    filter/Blur.cpp
)
target_include_directories(stages
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(stages
    PUBLIC core
    PRIVATE opencv_core opencv_imgproc ${OpenCV_LIBS}
)

target_include_directories(stages
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
