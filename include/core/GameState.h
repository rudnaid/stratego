#pragma once
#include "Board.h"
#include <Player.h>
#include <Unit.h>

#include <vector>

class GameState {
  Board board;
  std::vector<Player> players;
  int currentPlayerID = 0;

public:
  GameState();
  void setupInitialLayout();
  void togglePlayer();
  void executeMove(const Move &move);
  Board &getBoard();
  Player &getCurrentPlayer();
};
