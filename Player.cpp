#include "Player.h"
#include <Novice.h>

Player::Player() {
    posX = 640;
    posY = 360;
    playerSpeedX = 0;
    playerSpeedY = 0;
}

void Player::Initialize() {
    posX = 640;
    posY = 360;
}

void Player::Draw() {
    Novice::DrawEllipse(playerGetX(), playerGetY(), 40, 40, 0.0f, WHITE, kFillModeSolid);
}

void Player::move(char keys[]) {
    posX += playerSpeedX;
    posY += playerSpeedY;

    playerSpeedX = 0;
    playerSpeedY = 0;

    if (keys[DIK_RIGHT] || keys[DIK_D]) {
        playerSpeedX = 10;
    }
    if (keys[DIK_LEFT] || keys[DIK_A]) {
        playerSpeedX = -10;
    }
    if (keys[DIK_UP] || keys[DIK_W]) {
        playerSpeedY = -10;
    }
    if (keys[DIK_DOWN] || keys[DIK_S]) {
        playerSpeedY = 10;
    }
}

void Player::shoot() {
}