#include "NoMovementStrategy.h"

bool NoMovementStrategy::canMove(const Unit &unit, const Position &from,
                                 Position &to, const GameState &state) const {
  return false;
}
