#pragma once
#include <string>

#include "Move.h"

class ISDL2UI
{
public:
    virtual ~ISDL2UI() = default;
    virtual void init() = 0;
    virtual void pollEvents() = 0;
    virtual void render(const GameState& state) = 0;
    virtual Move getUserMove() = 0;
    virtual void loadTextures() = 0;
    virtual void cleanup() = 0;
    // virtual void setDragPiece(Unit* piece, const Position& pos) = 0;
    virtual void clearDragPiece() = 0;
    virtual void showMessage(const std::string& message) = 0;
};
