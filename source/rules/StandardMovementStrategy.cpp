#include "StandardMovementStrategy.h"
#include "IMovementStrategy.h"

namespace {
bool isAdjacent(const Position &from, const Position &to) {
  const int rowDiff = std::abs(to.row - from.row);
  const int colDiff = std::abs(to.col - from.col);

  if (!((rowDiff == 1 && colDiff == 0) || (rowDiff == 0 && colDiff == 1))) {
    return false;
  }
  return true;
}
} // namespace

bool StandardMovementStrategy::canMove(const Unit &unit, const Position &from,
                                       Position &to,
                                       const GameState &state) const {
  const Board &board = state.getBoard();

  if (Board::isWithinBounds(to) && !isDestTileLake(board, to) &&
      !isOccupiedByOwnUnit(board, to, unit) && isAdjacent(from, to))
    return true;

  return false;
}
