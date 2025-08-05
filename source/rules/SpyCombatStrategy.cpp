#include "SpyCombatStrategy.h"
#include "Unit.h"

CombatResult SpyCombatStrategy::resolve(Unit &attacker, Unit &defender) {
  if (defender.getRank() == UnitRank::Marshal) {
    return CombatResult::Win;
  }

  return CombatResult::Lose;
}
