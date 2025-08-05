#include "IMovementStrategy.h"
#include "Board.h"
#include "Position.h"
#include "Unit.h"
#include "GameState.h"

bool IMovementStrategy::isDestTileLake(const Board &board, const Position &to) {
  const Tile &destTile = board.getTile(to);

  if (destTile.getTerrain() == TerrainType::Lake)
    return true;
  return false;
}

bool IMovementStrategy::isOccupiedByOwnUnit(const Board &board, const Position &pos,
                                const Unit &unit) {
  const Unit *occupant = board.getTile(pos).getOccupant();
  return occupant != nullptr && occupant->getOwner() == unit.getOwner();
}