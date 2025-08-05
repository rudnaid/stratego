#pragma once

#include "Enums.h"
#include <string>

class PieceType {
  UnitRank rank;
  int power;
  int perPlayerCount;

public:
  PieceType(UnitRank rank, int power, int perPlayerCount);
  std::string getName() const;
  UnitRank getRank() const;
  int getPower() const;
  int getPerPlayerCount() const;
};
