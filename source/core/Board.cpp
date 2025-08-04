#include "Board.h"
#include "GameConfig.h"
#include <stdexcept>

Board::Board() : squares(GameConfig::ROWS * GameConfig::COLS) {

  for (const auto& lakePos : GameConfig::LAKE_POSITIONS()) {
    getSquare(lakePos) = Square(TerrainType::Lake);
  }
}

int Board::toIndex(const Position& pos) {
  if (!pos.isOnBoard())
    throw std::out_of_range("Position out of board bounds");
  return pos.getRow() * GameConfig::COLS + pos.getCol();
}

Square& Board::getSquare(const Position& pos) {
  return squares[toIndex(pos)];
}

const Square& Board::getSquare(const Position& pos) const {
  return squares[toIndex(pos)];
}

Unit* Board::getOccupant(const Position& pos) const {
  return getSquare(pos).getOccupant();
}

bool Board::isLake(const Position& pos) const {
  return getSquare(pos).getTerrain() == TerrainType::Lake;
}

void Board::setOccupant(const Position& pos, Unit* unit) {
  getSquare(pos).setOccupant(unit);
}

void Board::clearOccupant(const Position& pos) {
  getSquare(pos).clearOccupant();
}
