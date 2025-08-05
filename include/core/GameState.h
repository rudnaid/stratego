#pragma once
#include <memory>

#include "Move.h"

#include "Player.h"
#include "Unit.h"

#include <vector>

#include "Board.h"

class GameState {
  Board board;
  std::vector<Player> players;
  std::vector<Unit> unitsNotOnBoard;
  int currentPlayerID = 0;

public:
  GameState();
  void setupInitialLayout();
  void togglePlayer();
  void executeMove(const Move &move);
  const std::vector<Unit> &getUnitsNotOnBoard() const;
  Board &getBoard();
  const Board &getBoard() const;
  Player &getCurrentPlayer();
  const std::vector<Player> &getPlayers() const;
};
