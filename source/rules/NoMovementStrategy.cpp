#include "NoMovementStrategy.h"

bool NoMovementStrategy::canMove(const Unit &unit, const Position &from,
                                 const Position &to,
                                 const GameState &state) const {
  throw std::runtime_error("Not implemented");
}
