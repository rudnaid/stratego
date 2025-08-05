#include "GameController.h"

#include <iostream>
#include <map>
#include <vector>

#include "StandardCombatStrategy.h"
#include "StandardMovementStrategy.h"
using namespace std;

GameController::GameController(ISDL2UI *ui, GameState *gameState)
    : ui(ui), gameState(gameState) {}



GameController::~GameController() = default;

void GameController::stopGame() { isRunning = false; }

void GameController::initGame() {
    const vector<Player> &players = gameState->getPlayers();
    map<std::string, PieceType> pieceTypes = {
        { "Marshal",    PieceType(UnitRank::Marshal,    10, 1) },
        { "General",    PieceType(UnitRank::General,     9, 1) },
        { "Colonel",    PieceType(UnitRank::Colonel,     8, 2) },
        { "Major",      PieceType(UnitRank::Major,       7, 3) },
        { "Captain",    PieceType(UnitRank::Captain,     6, 4) },
        { "Lieutenant", PieceType(UnitRank::Lieutenant,  5, 4) },
        { "Sergeant",   PieceType(UnitRank::Sergeant,    4, 4) },
        { "Miner",      PieceType(UnitRank::Miner,       3, 5) },
        { "Scout",      PieceType(UnitRank::Scout,       2, 8) },
        { "Spy",        PieceType(UnitRank::Spy,         1, 1) },
        { "Bomb",       PieceType(UnitRank::Bomb,        0, 6) },
        { "Flag",       PieceType(UnitRank::Flag,        0, 1) }};


    StandardCombatStrategy combatStrategy;
    StandardMovementStrategy movementStrategy;

    vector<Unit> player1units;



    for (pair<const string, PieceType> &pieceType : pieceTypes) {
            for (int count = 1; count <= pieceType.second.getPerPlayerCount(); count++) {
                player1units.emplace_back(pieceType.second,players[0],combatStrategy,movementStrategy);
            }
        }
    ui->setupBoard(player1units, players[0]);
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
