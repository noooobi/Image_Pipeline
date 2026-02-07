find_package(OpenCV REQUIRED)
add_executable(image_pipeline_app
    main.cpp
)

target_link_libraries(image_pipeline_app
    PRIVATE core stages io ${OpenCV_LIBS}
)
