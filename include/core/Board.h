#pragma once
#include "Position.h"
#include "Square.h"
#include <vector>

class Board {
  std::vector<Square> squares;
  [[nodiscard]] static int toIndex(const Position& pos) ;
  static bool isWithinBounds(const Position& pos);

public:
  Board();

  Square& getSquare(const Position& pos);
  [[nodiscard]] const Square& getSquare(const Position& pos) const;

  [[nodiscard]] bool isLake(const Position& pos) const;
  Unit* getOccupant(const Position& pos) const;
  void setOccupant(const Position& pos, Unit* unit);
  void clearOccupant(const Position& pos);
};