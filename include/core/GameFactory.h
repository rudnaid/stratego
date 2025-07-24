#pragma once
#include "GameState.h"
#include "IGameController.h"
#include "IGameFactory.h"
#include "rules/IHistoryManager.h"
#include "rules/IRulesEngine.h"
#include "ui/ISDL2UI.h"

#include <memory>

class GameFactory : public IGameFactory {
  std::unique_ptr<ISDL2UI> ui;
  std::unique_ptr<GameState> state;
  std::unique_ptr<IRulesEngine> rules;
  std::unique_ptr<IHistoryManager> history;

public:
  std::unique_ptr<IGameController> createController() override;
};
