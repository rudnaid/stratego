#pragma once
#include "GameState.h"
#include "IGameController.h"
#include "ISDL2UI.h"
class GameController : public IGameController {

    GameState* gameState;
    ISDL2UI* ui;

    public:
    GameController(ISDL2UI* ui, GameState* gameState);
    ~GameController() override;
    void initGame() override;
    void startLoop() override;



};
