#include "GameController.h"

#include <iostream>
#include <vector>
using namespace std;

GameController::GameController(ISDL2UI *ui, GameState *gameState)
    : ui(ui), gameState(gameState) {}

GameController::~GameController() = default;

void GameController::stopGame() { isRunning = false; }

void GameController::initGame() {
     const vector<Player> &players = gameState->getPlayers();

    // vector<Unit> player1units = UnitFactory-> createUnitsForPlayer( globalPieceTypes, players[0] );
    // ui.setupBoard(player1units);
    //
    // vector<Unit> player2units = UnitFactory-> createUnitsForPlayer( globalPieceTypes, players[1] );
    // ui.setupBoard(player2units);


}

void GameController::startLoop() {
  cout << "loop start" << endl;
  while (isRunning) {
    ui->handleEvents();
  }
}
