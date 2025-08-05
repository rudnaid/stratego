#pragma once
#include "Move.h"

#include "Player.h"
#include "Unit.h"

#include <vector>

class Board;

class GameState {
  std::unique_ptr<Board> board;
  std::vector<Player> players;
  std::vector<Unit *> unitsNotOnBoard;
  int currentPlayerID = 0;

public:
  GameState();
  void setupInitialLayout();
  void togglePlayer();
  void executeMove(const Move &move);
  const std::vector<Unit *> &getUnitsNotOnBoard() const;
  Board &getBoard();
  const Board &getBoard() const;
  Player &getCurrentPlayer();
};
