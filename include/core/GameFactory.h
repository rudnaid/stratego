#pragma once
#include "GameState.h"
#include "IGameController.h"
#include "IGameFactory.h"
#include "IHistoryManager.h"
#include "IRulesEngine.h"
#include "ISDL2UI.h"

#include <memory>

class GameFactory final : public IGameFactory {
  std::unique_ptr<ISDL2UI> ui;
  std::unique_ptr<GameState> state;
  std::unique_ptr<IRulesEngine> rules;
  std::unique_ptr<IHistoryManager> history;

public:
  GameFactory() = default;
  ~GameFactory() override = default;

  std::unique_ptr<IGameController> createController() override;
};
