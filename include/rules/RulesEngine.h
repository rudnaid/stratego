#pragma once
#include "Enums.h"
#include "IRulesEngine.h"
#include "Move.h"
#include "Unit.h"

class RulesEngine final : public IRulesEngine {
  public:
  ~RulesEngine() override = default;
  bool isValidMove(const GameState &state, const Move &move) const;
  static CombatResult resolveCombat(Unit &attacker, Unit &defender);
};
