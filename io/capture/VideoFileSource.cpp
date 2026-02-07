#include "VideoFileSource.h"
#include <stdexcept>

VideoFileSource::VideoFileSource(const std::string &path)
    : cap_(path)
{
  if (!cap_.isOpened())
  {
    throw std::runtime_error("Failed to open video file");
  }
}

bool VideoFileSource::read(Frame &frame)
{
  cv::Mat img;
  cap_ >> img;
  if (img.empty())
    return false;

  frame.image = img;
  frame.timestamp = std::chrono::steady_clock::now();
  return true;
}
