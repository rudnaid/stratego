#pragma once

class IGameController {
public:
  virtual ~IGameController() = default;
  virtual void initGame() = 0;
  virtual void startLoop() = 0;
};
