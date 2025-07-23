#include <SDL.h>
#include <memory>;

#include "GameController.h"
#include "SDL2UIController.h"
using namespace std;

int main(int argc, char *argv[]) {
    auto ui = make_unique<SDL2UIController>();
    auto gameState = make_unique<GameState>();
    unique_ptr<IGameController> game = make_unique<GameController>(ui.get(), gameState.get());
    game->initGame();
    game->startLoop();


}