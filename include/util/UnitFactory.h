#pragma once

#include "GameConfig.h"
#include "Unit.h"

class UnitFactory {
public:
  static std::unique_ptr<Unit> createUnit(const std::string &name,
                                          const Player &owner);
  static std::vector<std::unique_ptr<Unit>> createUnitsForPlayer(const Player &owner);
};
