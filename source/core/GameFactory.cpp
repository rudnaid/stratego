#include "GameFactory.h"

#include "GameController.h"
#include "HistoryManager.h"
#include "RulesEngine.h"
#include "SDL2UIController.h"

#include <memory>

std::unique_ptr<IGameController> GameFactory::createController() {
  ui = std::make_unique<SDL2UIController>();
  state = std::make_unique<GameState>();
  // rules = std::make_unique<RulesEngine>();
  // history = std::make_unique<HistoryManager>();

  auto game = std::make_unique<GameController>(ui.get(), state.get());

  ui->setGameController(game.get());

  return game;
}
