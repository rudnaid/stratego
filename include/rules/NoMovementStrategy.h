#pragma once
#include "IMovementStrategy.h"

class NoMovementStrategy : IMovementStrategy {
public:
  [[nodiscard]] bool canMove(const Unit& unit, const Position& from, const Position& to, const GameState& state) const override;
};
