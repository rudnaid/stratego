#include "Tile.h"

#include "Unit.h"

Tile::Tile(const TerrainType terrain) : terrain(terrain), occupant(nullptr) {}

bool Tile::isEmpty() const {
  return occupant == nullptr;
}

TerrainType Tile::getTerrain() const {
  return terrain;
}

bool Tile::isLake(const Position& pos) const {
  return terrain == TerrainType::Lake;
}

Unit* Tile::getOccupant() const {
  return occupant;
}

void Tile::setOccupant(Unit* unit) {
  occupant = unit;
}

void Tile::clearOccupant() {
  occupant = nullptr;
}