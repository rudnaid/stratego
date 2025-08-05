#pragma once
#include "IMovementStrategy.h"

class NoMovementStrategy final : public IMovementStrategy {
public:
  ~NoMovementStrategy() override = default;
  [[nodiscard]] bool canMove(const Unit &unit, const Position &from,
                             Position &to,
                             const GameState &state) const override;
};
