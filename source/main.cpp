#include <iostream>
#include <memory>

#include "GameFactory.h"
#include "IGameFactory.h"

using namespace std;

int main(int argc, char *argv[]) {
  const auto gameFactory = make_unique<GameFactory>();

  const auto game = gameFactory->createController();

  game->startLoop();

  cout << "Exiting..." << endl;
  return 0;
}