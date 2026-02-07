#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "GrayscaleStage.h"
#include "Pipeline.h"
#include <iostream>

#include "capture/VideoFileSource.h"

int main(int argc, char **argv)
{
  try
  {
    std::string video_path = (argc > 1)
                                 ? argv[1]
                                 : "sample.mp4";
    VideoFileSource source(video_path);
    Frame frame;
    uint64_t frame_id = 0;
    Pipeline pipeline;
    pipeline.addStage(std::make_unique<GrayscaleStage>());

    cv::namedWindow("Output", cv::WINDOW_NORMAL);
    cv::resizeWindow("Output", 640, 360); // width, height
    while (source.read(frame))
    {
      pipeline.process(frame);

      frame.id = frame_id++;
      auto now = std::chrono::steady_clock::now();
      auto latency_ms =
          std::chrono::duration_cast<std::chrono::milliseconds>(
              now - frame.timestamp)
              .count();

      cv::putText(
          frame.image,
          "Latency: " + std::to_string(latency_ms) + " ms",
          cv::Point(20, 80),
          cv::FONT_HERSHEY_SIMPLEX,
          0.8,
          cv::Scalar(0, 255, 0),
          2);

      cv::putText(
          frame.image,
          "Frame: " + std::to_string(frame.id),
          cv::Point(20, 40),
          cv::FONT_HERSHEY_SIMPLEX,
          1.0,
          cv::Scalar(0, 255, 0),
          2);

      cv::imshow("Output", frame.image);

      if (cv::waitKey(30) == 27)
        break;
    }

    std::cout << "Video ended. Press any key to exit..." << std::endl;
    cv::waitKey(0);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }

  return 0;
}
