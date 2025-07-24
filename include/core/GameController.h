#pragma once
#include "GameState.h"
#include "IGameController.h"
#include "rules/IHistoryManager.h"
#include "rules/IRulesEngine.h"
#include "ui/ISDL2UI.h"

class GameController : public IGameController {
  GameState *gameState;
  ISDL2UI *ui;
  IRulesEngine *rulesEngine;
  IHistoryManager *history;

public:
  GameController(ISDL2UI *ui, GameState *gameState, IRulesEngine *rules,
                 IHistoryManager *history);
  void initGame() override;
  void startLoop() override;
};
