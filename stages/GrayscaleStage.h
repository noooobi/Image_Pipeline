#pragma once
#include "IStage.h"

class GrayscaleStage : public IStage
{
private:
  /* data */
public:
  void process(Frame &frame) override;
};
