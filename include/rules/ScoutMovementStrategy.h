#pragma once
#include "IMovementStrategy.h"

class ScoutMovementStrategy : IMovementStrategy {
public:
  [[nodiscard]] bool canMove(const Unit& unit, const Position& from, const Position& to, const GameState& state) const override;
};
