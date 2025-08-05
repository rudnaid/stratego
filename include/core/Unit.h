#pragma once
#include "PieceType.h"
#include "Player.h"
#include "ICombatStrategy.h"
#include "IMovementStrategy.h"

class Unit {
  PieceType& type;
  Player& owner;
  IMovementStrategy& moveStrategy;
  ICombatStrategy& combatStrategy;

public:
  Unit(PieceType& type, Player& owner, ICombatStrategy& combatStrategy, IMovementStrategy& moveStrategy);

  int getPower() const;
  Player& getOwner() const;
  std::string getName() const;
  UnitRank getRank() const;
  IMovementStrategy& getMoveStrategy() const;
  ICombatStrategy& getCombatStrategy() const;
};