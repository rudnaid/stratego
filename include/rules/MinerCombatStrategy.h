#pragma once
#include "ICombatStrategy.h"

class MinerCombatStrategy : ICombatStrategy {
public:
  CombatResult resolve(Unit &attacker, Unit &defender) override;
};
