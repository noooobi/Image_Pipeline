#include "Pipeline.h"

void Pipeline::addStage(std::unique_ptr<IStage> stage)
{
  stages_.push_back(std::move(stage));
}

void Pipeline::process(Frame &frame)
{
  for (auto &stage : stages_)
  {
    stage->process(frame);
  }
}