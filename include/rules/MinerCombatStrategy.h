#pragma once
#include "ICombatStrategy.h"

class MinerCombatStrategy final : ICombatStrategy {
public:
  ~MinerCombatStrategy() override = default;
  CombatResult resolve(Unit &attacker, Unit &defender) override;
};
