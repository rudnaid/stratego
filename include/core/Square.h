#pragma once
#include "Enums.h"

class Square {
  TerrainType terrain;
  Unit* occupant;

public:
  explicit Square(TerrainType terrain = TerrainType::Normal);
  [[nodiscard]] bool isEmpty() const;
  [[nodiscard]] TerrainType getTerrain() const;
  Unit* getOccupant() const;
  void setOccupant(Unit* unit);
  void clearOccupant();
};
