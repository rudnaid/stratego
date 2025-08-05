#pragma once

#include <string>
#include "UnitRank.h"
class PieceType {
  std::string name;
  UnitRank rank;
  int power;
  int perPlayerCount;
public:
  PieceType(std::string& name, UnitRank rank, int power, int perPlayerCount);
  std::string getName() const;
  UnitRank getRank() const;
  int getPower() const;
  int getPerPlayerCount() const;
};