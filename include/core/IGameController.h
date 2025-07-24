#pragma once

class IGameController {
public:
    virtual void initGame() = 0;
    virtual void startLoop() = 0;
    virtual ~IGameController() = default;
    virtual void stopGame() =0;
};