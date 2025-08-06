#include "Unit.h"
#include "ICombatStrategy.h"
#include "IMovementStrategy.h"

Unit::Unit(const PieceType &type, const Player &owner,
           std::shared_ptr<IMovementStrategy> moveStrategy,
           std::shared_ptr<ICombatStrategy> combatStrategy)
    : type(type),
      owner(owner),
      moveStrategy(std::move(moveStrategy)),
      combatStrategy(std::move(combatStrategy)) {}

int Unit::getPower() const { return type.getPower(); }

const Player &Unit::getOwner() const { return owner; }

const std::string Unit::getName() const { return type.getName(); }

UnitRank Unit::getRank() const { return type.getRank(); }

IMovementStrategy &Unit::getMoveStrategy() const { return *moveStrategy; }

ICombatStrategy &Unit::getCombatStrategy() const { return *combatStrategy; }
