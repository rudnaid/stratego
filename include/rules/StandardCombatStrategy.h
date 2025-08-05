#pragma once
#include "ICombatStrategy.h"

class StandardCombatStrategy final : ICombatStrategy {
public:
  ~StandardCombatStrategy() override = default;
  CombatResult resolve(Unit &attacker, Unit &defender) override;
};
