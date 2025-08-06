#include "GameState.h"
#include "Board.h"

GameState::GameState() {
  players = {Player(0, PlayerColor::Blue, false),
              Player(1, PlayerColor::Red, false)};
  board= Board();
};

void GameState::setupInitialLayout() {
  throw std::runtime_error("Not implemented");
}

void GameState::togglePlayer() {
  currentPlayerID = (currentPlayerID + 1) % players.size();
}
void GameState::executeMove(const Move &move) {
  Unit *occupant = board.getOccupant(move.from);
  board.setOccupant(move.to, occupant);
  board.clearOccupant(move.from);
}
std::vector<std::unique_ptr<Unit>> &GameState::getUnitsNotOnBoard() {
  return unitsNotOnBoard;
}

Board &GameState::getBoard() { return board; }

const Board &GameState::getBoard() const {
  return board;
}

Player &GameState::getCurrentPlayer() { return players.at(currentPlayerID); }

const std::vector<Player> &GameState::getPlayers() const {
  return players;
}
void GameState::addUnitsNotOnBoard(std::vector<std::unique_ptr<Unit>> &units) {
  for (auto &unit : units) {
    unitsNotOnBoard.emplace_back(std::move(unit));
  }

}
bool GameState::addUnitToBoard(Move &move ) {
  return true;

}


