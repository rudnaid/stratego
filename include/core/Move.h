#pragma once
#include "Position.h"
#include "GameState.h"

class Move {
    Position from;
    Position to;

public:
    Move(const Position& from, const Position& to);

    void execute(GameState& state);
    void undo(GameState& state);
    bool isValid(GameState& state) const;

    [[nodiscard]] const Position& getFrom() const;
    [[nodiscard]] const Position& getTo() const;
};