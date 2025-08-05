#include "Board.h"
#include "GameConfig.h"
#include "Unit.h"

#include <stdexcept>

Board::Board() : tiles(GameConfig::ROWS * GameConfig::COLS) {

  for (const auto& lakePos : GameConfig::LAKE_POSITIONS()) {
    getTile(lakePos) = Tile(TerrainType::Lake);
  }
}

bool Board::isWithinBounds(const Position& pos) {
  return pos.row() >= 0 && pos.row() < GameConfig::ROWS &&
         pos.col() >= 0 && pos.col() < GameConfig::COLS;
}

int Board::toIndex(const Position& pos) {
  if (!isWithinBounds(pos))
    throw std::out_of_range("Position out of board bounds");
  return pos.row() * GameConfig::COLS + pos.col();
}

Tile& Board::getTile(const Position& pos) {
  return tiles[toIndex(pos)];
}

const Tile& Board::getTile(const Position& pos) const {
  return tiles[toIndex(pos)];
}

Unit* Board::getOccupant(const Position& pos) const {
  return getTile(pos).getOccupant();
}

void Board::setOccupant(const Position& pos, Unit* unit) {
  getTile(pos).setOccupant(unit);
}

void Board::clearOccupant(const Position& pos) {
  getTile(pos).clearOccupant();
}
