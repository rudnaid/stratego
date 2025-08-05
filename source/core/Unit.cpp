#include "Unit.h"
#include "IMovementStrategy.h"
#include "ICombatStrategy.h"

Unit::Unit(PieceType &type, const Player &owner, ICombatStrategy &combatStrategy,
           IMovementStrategy &moveStrategy)
    : type(type), owner(owner), moveStrategy(moveStrategy),
      combatStrategy(combatStrategy) {}

int Unit::getPower() const { return type.getPower(); }

const Player &Unit::getOwner() const { return owner; }

const std::string Unit::getName() const { return type.getName(); }

UnitRank Unit::getRank() const { return type.getRank(); }

IMovementStrategy &Unit::getMoveStrategy() const { return moveStrategy; }

ICombatStrategy &Unit::getCombatStrategy() const { return combatStrategy; }
