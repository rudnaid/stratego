#pragma once
#include "Enums.h"

class Unit;

class ICombatStrategy {
public:
  virtual ~ICombatStrategy() = default;
  virtual CombatResult resolve(Unit &attacker, Unit &defender) = 0;
};
