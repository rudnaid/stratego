#pragma once
#include "ISDL2UI.h"

class GameState;

class SDL2UIController : public ISDL2UI {
    public:
    ~SDL2UIController() override = default;
    void init() override;
    void pollEvents() override;
    void render(const GameState& state) override;
    Move getUserMove() override;
    void loadTextures() override;
    void cleanup() override;
    // void setDragPiece(Unit* piece, const Position& pos) override;
    void clearDragPiece() override;
    void showMessage(const std::string& message) override;

};
