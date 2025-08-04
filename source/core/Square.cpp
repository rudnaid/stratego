#include "Square.h"

Square::Square(const TerrainType terrain) : terrain(terrain), occupant(nullptr) {}

bool Square::isEmpty() const {
  return occupant == nullptr;
}

TerrainType Square::getTerrain() const {
  return terrain;
}

Unit* Square::getOccupant() const {
  return occupant;
}

void Square::setOccupant(Unit* unit) {
  occupant = unit;
}

void Square::clearOccupant() {
  occupant = nullptr;
}