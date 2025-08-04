#pragma once
#include <vector>

class Position {
  int row;
  int col;
public:
  Position(int row, int col);
  [[nodiscard]] bool isOnBoard() const;
  [[nodiscard]] std::vector<Position> neighbors() const;
  [[nodiscard]] int getRow() const;
  [[nodiscard]] int getCol() const;
  bool operator==(const Position& other) const;
};
