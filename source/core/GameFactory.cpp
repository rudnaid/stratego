#include "core/GameController.h"
#include <core/GameFactory.h>
#include <functional>

std::unique_ptr<IGameController> GameFactory::createController() {
  ui = std::make_unique<ISDL2UI>();
  state = std::make_unique<GameState>();
  rules = std::make_unique<IRulesEngine>();
  history = std::make_unique<IHistoryManager>();

  return std::make_unique<GameController>(ui.get(), state.get(), rules.get(),
                                          history.get());
}
