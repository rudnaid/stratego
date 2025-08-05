#pragma once
#include "Enums.h"
#include "Unit.h"

class ICombatStrategy {
public:
  virtual ~ICombatStrategy() = default;
  virtual CombatResult resolve(Unit &attacker, Unit &defender) = 0;
};
