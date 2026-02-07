#include <memory>
#include <vector>

#include "IStage.h"

class Pipeline
{
public:
  void addStage(std::unique_ptr<IStage> stage);
  void process(Frame &frame);

private:
  std::vector<std::unique_ptr<IStage>> stages_;
};