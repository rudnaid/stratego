#include "GameController.h"

#include "UnitFactory.h"
#include <iostream>
#include <vector>

using namespace std;

GameController::GameController(ISDL2UI *ui, GameState *gameState)
    : ui(ui), gameState(gameState) {}

GameController::~GameController() = default;

void GameController::stopGame() { isRunning = false; }

void GameController::initGame() {
  const vector<Player> &players = gameState->getPlayers();


  for (const auto &player : players) {
    bool unitPlacement = true;
    auto playerUnits = UnitFactory::createUnitsForPlayer(player);
    gameState->addUnitsNotOnBoard(playerUnits);
    auto &allUnitsNotOnBoard = gameState->getUnitsNotOnBoard();

    ui->setupBoard(allUnitsNotOnBoard, player);

    while (unitPlacement) {
      ui->handleEvents();
    }


  }
}

void GameController::startLoop() {
  cout << "loop start" << endl;
  while (isRunning) {
    ui->handleEvents();
  }
}
