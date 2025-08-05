#pragma once
#include "Enums.h"

class Player {
  int id;
  PlayerColor color;
  bool isHuman;

public:
  Player(int id, PlayerColor color, bool isHuman);
  [[nodiscard]] int getID() const;
  [[nodiscard]] PlayerColor getColor() const;
  [[nodiscard]] bool isHumanPlayer() const;
  bool operator==(const Player & ) const = default;
};
