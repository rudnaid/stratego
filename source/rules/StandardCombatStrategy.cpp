#include "StandardCombatStrategy.h"

CombatResult StandardCombatStrategy::resolve(Unit &attacker, Unit &defender) {
  const int attackerPower = attacker.getPower();
  const int defenderPower = defender.getPower();

  if (attackerPower > defenderPower) {
    return CombatResult::Win;
  }

  if (attackerPower < defenderPower) {
    return CombatResult::Lose;
  }

  return CombatResult::Draw;
}
