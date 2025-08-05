#pragma once
#include "GameState.h"

class IMovementStrategy {
  public:
  virtual ~IMovementStrategy() = default;
  [[nodiscard]] virtual bool canMove(const Unit& unit, const Position& from, const Position& to, const GameState& state) const = 0;
};
