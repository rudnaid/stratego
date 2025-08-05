#pragma once
#include "Position.h"
#include "Tile.h"
#include "Unit.h"

#include <vector>

class Board {
  std::vector<Tile> tiles;
  [[nodiscard]] static int toIndex(const Position& pos) ;
  static bool isWithinBounds(const Position& pos);

public:
  Board();

  Tile& getTile(const Position& pos);
  [[nodiscard]] const Tile& getTile(const Position& pos) const;

  [[nodiscard]] Unit* getOccupant(const Position& pos) const;
  void setOccupant(const Position& pos, Unit* unit);
  void clearOccupant(const Position& pos);
};