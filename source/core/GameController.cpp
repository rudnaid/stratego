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
    auto playerUnits = UnitFactory::createUnitsForPlayer(player);
    auto &buffer = gameState->getUnitsNotOnBoard();

    for (auto &unit : playerUnits) {
      buffer.push_back(std::move(unit));
    }

    auto &allUnits = gameState->getUnitsNotOnBoard();
    ui->setupBoard(allUnits, player);
  }
}

void GameController::startLoop() {
  cout << "loop start" << endl;
  while (isRunning) {
    ui->handleEvents();
  }
}
