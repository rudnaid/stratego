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
  std::vector<std::unique_ptr<Unit>> unitsNotOnBoard;
  int currentPlayerID = 0;

public:
  GameState();
  void setupInitialLayout();
  void togglePlayer();
  void executeMove(const Move &move);
  std::vector<std::unique_ptr<Unit>> &getUnitsNotOnBoard();
  void addUnitsNotOnBoard(std::vector<std::unique_ptr<Unit>> &units);
  bool addUnitToBoard(Move &move);
  Board &getBoard();
  const Board &getBoard() const;
  Player &getCurrentPlayer();
  const std::vector<Player> &getPlayers() const;
};
