#pragma once

#include <string>

enum class UnitRank {
  Marshal,      // 10
  General,      // 9
  Colonel,      // 8
  Major,        // 7
  Captain,      // 6
  Lieutenant,   // 5
  Sergeant,     // 4
  Miner,        // 3
  Scout,        // 2
  Spy,          // 1
  Bomb,         // (special)
  Flag          // (special)
};

inline std::string toString(const UnitRank rank) {
  switch(rank) {
  case UnitRank::Marshal:    return "Marshal";
  case UnitRank::General:    return "General";
  case UnitRank::Colonel:    return "Colonel";
  case UnitRank::Major:      return "Major";
  case UnitRank::Captain:    return "Captain";
  case UnitRank::Lieutenant: return "Lieutenant";
  case UnitRank::Sergeant:   return "Sergeant";
  case UnitRank::Miner:      return "Miner";
  case UnitRank::Scout:      return "Scout";
  case UnitRank::Spy:        return "Spy";
  case UnitRank::Bomb:       return "Bomb";
  case UnitRank::Flag:       return "Flag";
  default:                   return "Unknown";
  }
}

enum class PlayerColor {
  Red,
  Blue
};

enum class CombatResult {
  Win,
  Lose,
  Draw
};

enum class TerrainType {
  Normal,
  Lake
};

enum class GameOutcome {
  RedWins,
  BlueWins,
  Draw,
  InProgress
};
