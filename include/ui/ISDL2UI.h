#pragma once
#include <string>

#include "GameState.h"
#include "Move.h"

class ISDL2UI {
public:
  virtual ~ISDL2UI() = default;
  virtual bool init() = 0;
  virtual void handleEvents() = 0;
  virtual void render() = 0;
  virtual void renderLoop(int delay) = 0;
  virtual void closeThread() = 0;
  virtual Move getUserMove() = 0;
  virtual void loadTextures() = 0;
  virtual void initLayout() = 0;
  virtual void cleanup() = 0;
  // virtual void setDragPiece(Unit* piece, const Position& pos) = 0;
  virtual void clearDragPiece() = 0;
  virtual void showMessage(const std::string &message) = 0;
  virtual void setGameController(IGameController *gameController) = 0;
  virtual void setupBoard(const std::vector<std::unique_ptr<Unit>> &units, const Player &currentPlayer) = 0;
};
