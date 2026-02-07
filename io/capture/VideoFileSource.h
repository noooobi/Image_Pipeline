#pragma once
#include "IFrameSource.h"
#include <opencv2/videoio.hpp>

class VideoFileSource : public IFrameSource
{
public:
  explicit VideoFileSource(const std::string &path);
  bool read(Frame &frame) override;

private:
  cv::VideoCapture cap_;
};
