#include "GrayscaleStage.h"
#include <opencv2/imgproc.hpp>

void GrayscaleStage::process(Frame &frame)
{
  if (frame.image.empty())
    return;
  cv::cvtColor(frame.image, frame.image, cv::COLOR_BGR2GRAY);
}