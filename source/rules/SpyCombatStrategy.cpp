#include "SpyCombatStrategy.h"

CombatResult SpyCombatStrategy::resolve(Unit &attacker, Unit &defender) {
  if (defender.getRank() == UnitRank::Marshal) {
    return CombatResult::Win;
  }

  return CombatResult::Lose;
}
