#include "Player.h"

Player::Player(const int id, const PlayerColor color, const bool isHuman)
    : id(id), color(color), isHuman(isHuman) {}

int Player::getID() const {
    return id;
}

PlayerColor Player::getColor() const {
    return color;
}

bool Player::isHumanPlayer() const {
    return isHuman;
}
