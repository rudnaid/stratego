#include <memory>

#include "core/GameFactory.h"
#include "core/IGameController.h"

int main(int argc, char *argv[]) {
  const auto factory = std::make_unique<GameFactory>();
  const auto game = factory->createController();

  game->initGame();
  game->startLoop();
}
