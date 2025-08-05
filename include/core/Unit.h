#pragma once
#include "PieceType.h"

class Unit {
  PieceType& type;
  Player& owner;
  IMovementStrategy& moveStrategy;
  ICombatStrategy& combatStrategy;

public:
  Unit(PieceType& type, Player& owner, ICombatStrategy& combatStrategy, IMoveStrategy& moveStrategy);

  int getPower() const;
  Player& getOwner() const;
  std::string getName() const;
};