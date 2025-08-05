using namespace std;
#include "PieceType.h"

PieceType::PieceType(string& name, UnitRank rank, int power, int perPlayerCount) : name(name), rank(rank), power(power), perPlayerCount(perPlayerCount) {};
PieceType::getName() const {
  return name;
};

PieceType::getRank() const {
  return rank;
}

PieceType::getPower() const {
  return power;
}

PieceType::getPerPlayerCount() const {
  return perPlayerCount;
}

