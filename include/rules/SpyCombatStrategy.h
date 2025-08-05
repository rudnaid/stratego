#pragma once
#include "ICombatStrategy.h"

class SpyCombatStrategy : ICombatStrategy {
public:
  CombatResult resolve(Unit &attacker, Unit &defender) override;
};
