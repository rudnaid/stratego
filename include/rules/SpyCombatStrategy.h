#pragma once
#include "ICombatStrategy.h"

class SpyCombatStrategy final : public ICombatStrategy {
public:
  ~SpyCombatStrategy() override = default;
  CombatResult resolve(Unit &attacker, Unit &defender) override;
};
