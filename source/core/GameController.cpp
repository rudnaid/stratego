#include "GameController.h"

#include <iostream>
using namespace std;

GameController::GameController(ISDL2UI *ui, GameState *gameState)
    : ui(ui), gameState(gameState) {}

GameController::~GameController() = default;

void GameController::stopGame() { isRunning = false; }

void GameController::initGame() {}

void GameController::startLoop() {
  cout << "loop start" << endl;
  while (isRunning) {
    ui->handleEvents();
  }
}
