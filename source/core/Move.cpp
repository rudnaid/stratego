#include "Move.h"

Move::Move(const Position& from, const Position& to)
    : from(from), to(to) {}

void Move::execute(GameState& state) {
  Unit* unit = state.getBoard().getOccupant(from);
  state.getBoard().setOccupant(to, unit);
  state.getBoard().clearOccupant(from);
}

void Move::undo(GameState& state) {
  throw std::runtime_error("Not implemented");
}

bool Move::isValid(GameState& state) const {
  if (!from.isOnBoard() || !to.isOnBoard())
    return false;

  Unit* movingUnit = state.getBoard().getOccupant(from);

  if (!movingUnit)
    return false;
  if (from == to)
    return false;

  return true;
}

const Position& Move::getFrom() const {
  return from;
}

const Position& Move::getTo() const {
  return to;
}