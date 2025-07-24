#include <core/GameController.h>

GameController::GameController(ISDL2UI *ui, GameState *gameState,
                               IRulesEngine *rules, IHistoryManager *history)
    : gameState(gameState), ui(ui), rulesEngine(rules), history(history) {}

void GameController::initGame() {}

void GameController::startLoop() {}
