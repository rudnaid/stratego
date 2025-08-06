#include "GameConfig.h"

const std::vector<Position> &GameConfig::LAKE_POSITIONS() {
  static const std::vector<Position> lakes = {{4, 2}, {4, 3}, {5, 2}, {5, 3},
                                              {4, 6}, {4, 7}, {5, 6}, {5, 7}};
  return lakes;
}

const std::map<std::string, PieceType> GameConfig::PIECE_TYPES = {
  { "Marshal",    PieceType(UnitRank::Marshal,    10, 1) },
  { "General",    PieceType(UnitRank::General,     9, 1) },
  { "Colonel",    PieceType(UnitRank::Colonel,     8, 2) },
  { "Major",      PieceType(UnitRank::Major,       7, 3) },
  { "Captain",    PieceType(UnitRank::Captain,     6, 4) },
  { "Lieutenant", PieceType(UnitRank::Lieutenant,  5, 4) },
  { "Sergeant",   PieceType(UnitRank::Sergeant,    4, 4) },
  { "Miner",      PieceType(UnitRank::Miner,       3, 5) },
  { "Scout",      PieceType(UnitRank::Scout,       2, 8) },
  { "Spy",        PieceType(UnitRank::Spy,         1, 1) },
  { "Bomb",       PieceType(UnitRank::Bomb,        0, 6) },
  { "Flag",       PieceType(UnitRank::Flag,        0, 1) }
};
