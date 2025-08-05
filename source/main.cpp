#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include <memory>

#include "GameFactory.h"
#include "IGameFactory.h"



using namespace std;

int main(int argc, char *argv[]) {
  const std::unique_ptr<IGameFactory> factory = make_unique<GameFactory>();

  const auto game = factory->createController();
  //game->initGame();
  game->startLoop();

  cout << "Exiting..." << endl;
  return 0;
}