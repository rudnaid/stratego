#pragma once
#include "GameState.h"
#include "Board.h"
#include "Position.h"
#include "Unit.h"

class GameState;
class Board;
struct Position;
class Unit;

class IMovementStrategy {
public:
  virtual ~IMovementStrategy() = default;
  [[nodiscard]] virtual bool canMove(const Unit &unit, const Position &from,
                                     Position &to,
                                     const GameState &state) const = 0;

protected:
  static bool isDestTileLake(const Board &board, const Position &to);

  static bool isOccupiedByOwnUnit(const Board &board, const Position &pos,
                                  const Unit &unit);
};
