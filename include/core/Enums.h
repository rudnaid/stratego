#pragma once

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
