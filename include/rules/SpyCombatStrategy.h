#pragma once
#include "ICombatStrategy.h"

class SpyCombatStrategy final : ICombatStrategy {
public:
  ~SpyCombatStrategy() override = default;
  CombatResult resolve(Unit &attacker, Unit &defender) override;
};
