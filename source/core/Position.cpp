#include "Position.h"
#include "GameConfig.h"

Position::Position(const int row, const int col) : row(row), col(col) {}

bool Position::isOnBoard() const {
  return row >= 0 && row < GameConfig::ROWS && col >= 0 &&
         col < GameConfig::COLS;
}

std::vector<Position> Position::neighbors() const {
  std::vector<Position> result;

  if (row > 0)
    result.emplace_back(row - 1, col);
  if (row < GameConfig::ROWS - 1)
    result.emplace_back(row + 1, col);
  if (col > 0)
    result.emplace_back(row, col - 1);
  if (col < GameConfig::COLS - 1)
    result.emplace_back(row, col + 1);

  return result;
}

int Position::getRow() const {
  return row;
}

int Position::getCol() const {
  return col;
}

bool Position::operator==(const Position& other) const {
  return row == other.row && col == other.col;
}
