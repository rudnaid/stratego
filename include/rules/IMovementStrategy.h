#pragma once
#include "GameState.h"

class Unit;

class IMovementStrategy {
public:
  virtual ~IMovementStrategy() = default;
  [[nodiscard]] virtual bool canMove(const Unit &unit, const Position &from,
                                     Position &to,
                                     const GameState &state) const = 0;

protected:
  static bool isDestTileLake(const Board &board, const Position &to) {
    const Tile &destTile = board.getTile(to);

    if (destTile.getTerrain() == TerrainType::Lake)
      return true;
    return false;
  }

  static bool isOccupiedByOwnUnit(const Board &board, const Position &pos,
                                  const Unit &unit) {
    const Unit *occupant = board.getTile(pos).getOccupant();
    return occupant != nullptr && occupant->getOwner() == unit.getOwner();
  }
};
