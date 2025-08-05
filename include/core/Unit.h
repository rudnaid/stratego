#pragma once
#include "PieceType.h"
#include "Player.h"

class IMovementStrategy;
class ICombatStrategy;

class Unit {
  PieceType& type;
  const Player& owner;
  IMovementStrategy& moveStrategy;
  ICombatStrategy& combatStrategy;

public:
  Unit(PieceType& type,const Player& owner, ICombatStrategy& combatStrategy, IMovementStrategy& moveStrategy);

  int getPower() const;
  const Player& getOwner() const;

  const std::string getName() const;
  UnitRank getRank() const;
  IMovementStrategy& getMoveStrategy() const;
  ICombatStrategy& getCombatStrategy() const;
};