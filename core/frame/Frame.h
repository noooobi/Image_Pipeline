#pragma once
#include <opencv4/opencv2/core.hpp>
#include <chrono>

struct Frame
{
  uint64_t id;
  std::chrono::steady_clock::time_point timestamp;
  cv::Mat image;
};
