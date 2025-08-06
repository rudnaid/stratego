#pragma once
#include "PieceType.h"
#include "Player.h"

class IMovementStrategy;
class ICombatStrategy;

class Unit {
  const PieceType &type;
  const Player &owner;
  std::shared_ptr<IMovementStrategy> moveStrategy;
  std::shared_ptr<ICombatStrategy> combatStrategy;

public:
  Unit(const PieceType &type, const Player &owner,
       std::shared_ptr<IMovementStrategy> moveStrategy,
       std::shared_ptr<ICombatStrategy> combatStrategy);

  int getPower() const;
  const Player &getOwner() const;

  const std::string getName() const;
  UnitRank getRank() const;
  IMovementStrategy &getMoveStrategy() const;
  ICombatStrategy &getCombatStrategy() const;
};