#include "RulesEngine.h"

#include "Move.h"

CombatResult RulesEngine::resolveCombat(Unit &attacker, Unit &defender) {
  return attacker.getCombatStrategy().resolve(attacker, defender);
}

bool RulesEngine::isValidMove(const GameState &state, const Move &move) const {
  const Board &board = state.getBoard();
  const Position &from = move.from;
  const Position &to = move.to;

  Unit *unit = board.getOccupant(from);
  if (!unit)
    return false;

  return unit->getMoveStrategy().canMove(*unit, from, to, state);
}
