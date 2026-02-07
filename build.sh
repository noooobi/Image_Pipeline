echo "Running image pipeline..."
cmake -S . -B build
cmake --build build --target image_pipeline_app
