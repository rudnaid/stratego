#include "Unit.h"


Unit::Unit(PieceType &type, Player &owner, ICombatStrategy &combatStrategy, IMovementStrategy &moveStrategy) : type(type), owner(owner), combatStrategy(combatStrategy), moveStrategy(moveStrategy){};

int Unit::getPower() const {
    return type.getPower();
};
Player& Unit::getOwner() const {
  return owner;
};
std::string Unit::getName() const {
  return type.getName();
};
