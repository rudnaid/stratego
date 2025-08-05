#pragma once
#include "ICombatStrategy.h"

class StandardCombatStrategy final : public ICombatStrategy {
public:
  ~StandardCombatStrategy() override = default;
  CombatResult resolve(Unit &attacker, Unit &defender) override;
};
