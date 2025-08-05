#pragma once
#include "Enums.h"
#include "Position.h"
#include "Unit.h"

class Tile {
  TerrainType terrain;
  Unit* occupant;

public:
  explicit Tile(TerrainType terrain = TerrainType::Normal);
  [[nodiscard]] bool isEmpty() const;
  [[nodiscard]] TerrainType getTerrain() const;
  [[nodiscard]] bool isLake(const Position& pos) const;
  [[nodiscard]] Unit* getOccupant() const;
  void setOccupant(Unit* unit);
  void clearOccupant();
};
