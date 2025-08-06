#include "UnitFactory.h"

#include "NoMovementStrategy.h"
#include "ScoutMovementStrategy.h"
#include "StandardMovementStrategy.h"
#include "StandardCombatStrategy.h"
#include "MinerCombatStrategy.h"
#include "SpyCombatStrategy.h"

std::unique_ptr<Unit> UnitFactory::createUnit(const std::string &name, const Player &owner) {
  const PieceType &type = GameConfig::PIECE_TYPES.at(name);

  static auto noMove = std::make_shared<NoMovementStrategy>();
  static auto scoutMove = std::make_shared<ScoutMovementStrategy>();
  static auto standardMove = std::make_shared<StandardMovementStrategy>();

  static auto spyCombat = std::make_shared<SpyCombatStrategy>();
  static auto minerCombat = std::make_shared<MinerCombatStrategy>();
  static auto standardCombat = std::make_shared<StandardCombatStrategy>();

  std::shared_ptr<IMovementStrategy> movementStrategy;
  std::shared_ptr<ICombatStrategy> combatStrategy;

  if (name == "Bomb" || name == "Flag") {
    movementStrategy = noMove;
  } else if (name == "Scout") {
    movementStrategy = scoutMove;
  } else {
    movementStrategy = standardMove;
  }

  if (name == "Spy") {
    combatStrategy = spyCombat;
  } else if (name == "Miner") {
    combatStrategy = minerCombat;
  } else {
    combatStrategy = standardCombat;
  }

  return std::make_unique<Unit>(type, owner, movementStrategy, combatStrategy);
}

std::vector<std::unique_ptr<Unit>> UnitFactory::createUnitsForPlayer(const Player& owner) {
  std::vector<std::unique_ptr<Unit>> units;

  for (const auto& [name, type] : GameConfig::PIECE_TYPES) {
    for (int i = 0; i < type.getPerPlayerCount(); ++i) {
      units.push_back(createUnit(name, owner));
    }
  }
  return units;
}