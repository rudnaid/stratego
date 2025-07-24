#pragma once

#include <core/IGameController.h>
#include <memory>

class IGameFactory {
public:
  virtual ~IGameFactory() = default;
  virtual std::unique_ptr<IGameController> createController() = 0;
};
