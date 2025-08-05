#pragma once
#include "IMovementStrategy.h"

class StandardMovementStrategy final : public IMovementStrategy {
public:
  ~StandardMovementStrategy() override = default;
  [[nodiscard]] bool canMove(const Unit &unit, const Position &from,
                             Position &to,
                             const GameState &state) const override;
};
