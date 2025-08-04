#include <GameState.h>

GameState::GameState()
    : players{Player(0, PlayerColor::Blue, false),
              Player(1, PlayerColor::Red, false)} {}

void GameState::setupInitialLayout() {
  throw std::runtime_error("Not implemented");
}

void GameState::togglePlayer() {
  currentPlayerID = (currentPlayerID + 1) % players.size();
}

Board &GameState::getBoard() { return board; }

Player GameState::getCurrentPlayer() { return players.at(currentPlayerID); }
