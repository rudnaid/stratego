#pragma once
#include "IMovementStrategy.h"

class ScoutMovementStrategy final : public IMovementStrategy {
public:
  ~ScoutMovementStrategy() override = default;
  [[nodiscard]] bool canMove(const Unit &unit, const Position &from,
                             Position &to,
                             const GameState &state) const override;
};
