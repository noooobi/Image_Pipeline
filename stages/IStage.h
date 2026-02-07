#pragma once
#include "frame/Frame.h"

class IStage
{
public:
  virtual ~IStage() = default;
  virtual void process(Frame &frame) = 0;
};