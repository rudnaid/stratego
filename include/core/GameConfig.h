#pragma once
#include "PieceType.h"
#include "Position.h"

#include <map>
#include <vector>

class GameConfig {
public:
  static constexpr int ROWS = 10;
  static constexpr int COLS = 10;

  static const std::vector<Position> &LAKE_POSITIONS();
  static const std::map<std::string, PieceType> PIECE_TYPES;
};

