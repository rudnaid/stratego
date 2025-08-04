#include "GameConfig.h"

const std::vector<Position> &GameConfig::LAKE_POSITIONS() {
  static const std::vector<Position> lakes = {{4, 2}, {4, 3}, {5, 2}, {5, 3},
                                              {4, 6}, {4, 7}, {5, 6}, {5, 7}};
  return lakes;
}
