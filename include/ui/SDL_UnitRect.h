#pragma once
#include <SDL_rect.h>

#include "Enums.h"
#include "Player.h"

class SDL_UnitRect : public SDL_Rect {
public:
    SDL_UnitRect() = default;
    SDL_UnitRect(const UnitRank rank, const Player &player) : SDL_Rect(), rank(rank), player(player) {
    }

    const UnitRank rank;
    const Player &player;
};
