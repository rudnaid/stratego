#pragma once
#include "Board.h"
#include <Player.h>

#include <vector>

class GameState {
  Board board;
  std::vector<Player> players;
  int currentPlayerID = 0;

public:
  GameState();
  void setupInitialLayout();
  void togglePlayer();
  Board& getBoard();
  Player getCurrentPlayer();
};
