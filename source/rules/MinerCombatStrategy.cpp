#include "MinerCombatStrategy.h"
#include "Unit.h"

CombatResult MinerCombatStrategy::resolve(Unit &attacker, Unit &defender) {
  if (defender.getRank() == UnitRank::Bomb) {
    return CombatResult::Win;
  }

  const int attackerPower = attacker.getPower();
  const int defenderPower = defender.getPower();

  if (attackerPower > defenderPower) {
    return CombatResult::Win;
  } else if (attackerPower < defenderPower) {
    return CombatResult::Lose;
  } else {
    return CombatResult::Draw;
  }
}
