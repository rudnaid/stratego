#pragma once

#include <IGameController.h>
#include <memory>

class IGameFactory {
public:
  virtual ~IGameFactory() = default;
  virtual std::unique_ptr<IGameController> createController() = 0;
};
