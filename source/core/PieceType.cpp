using namespace std;
#include "PieceType.h"

PieceType::PieceType(const UnitRank rank, const int power, int perPlayerCount)
    : rank(rank), power(power), perPlayerCount(perPlayerCount) {}

std::string PieceType::getName() const { return toString(rank); }

UnitRank PieceType::getRank() const { return rank; }

int PieceType::getPower() const { return power; }

int PieceType::getPerPlayerCount() const { return perPlayerCount; }
