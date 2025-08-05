#pragma once
#include "Position.h"
#include <vector>

class GameConfig {
public:
  static constexpr int ROWS = 10;
  static constexpr int COLS = 10;

  static const std::vector<Position> &LAKE_POSITIONS();
};
