#include "ScoutMovementStrategy.h"
#include "IMovementStrategy.h"

namespace {
bool isLakeOrOccupied(const Board &board, const Position &pos) {
  const Tile &tile = board.getTile(pos);
  return tile.getTerrain() == TerrainType::Lake || !tile.isEmpty();
}

bool isHorizontalPathClear(const Board &board, int row, int fromCol, int toCol) {
  const int colStart = std::min(fromCol, toCol) + 1;
  const int colEnd = std::max(fromCol, toCol);

  for (int col = colStart; col < colEnd; ++col) {
    Position pos{row, col};

    if (isLakeOrOccupied(board, pos)) {
      return false;
    }
  }

  return true;
}

bool isVerticalPathClear(const Board &board, int col, int fromRow, int toRow) {
  const int rowStart = std::min(fromRow, toRow) + 1;
  const int rowEnd = std::max(fromRow, toRow);

  for (int row = rowStart; row < rowEnd; ++row) {
    Position pos{row, col};

    if (isLakeOrOccupied(board, pos)) {
      return false;
    }
  }

  return true;
}
} // namespace

bool ScoutMovementStrategy::canMove(const Unit &unit, const Position &from,
                                    Position &to,
                                    const GameState &state) const {
  const Board &board = state.getBoard();

  if (!board.isWithinBounds(to) || isDestTileLake(board, to) ||
      isOccupiedByOwnUnit(board, to, unit))
    return false;

  if (from.row == to.row) {
    return isHorizontalPathClear(board, from.row, from.col, to.col);
  }

  if (from.col == to.col) {
    return isVerticalPathClear(board, from.col, from.row, to.row);
  }

  return false;
}
