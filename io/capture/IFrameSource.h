#pragma once
#include <opencv2/core.hpp>
#include "frame/Frame.h"

class IFrameSource
{
public:
  virtual ~IFrameSource() = default;
  virtual bool read(Frame &frame) = 0;
};
