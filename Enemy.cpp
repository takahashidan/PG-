#include "Enemy.h"

Enemy::Enemy() {
	enemyPosX = 300;
	enemyPosY = 200;
	enemySpeed = 10;
}

void Enemy::Draw() {
	Novice::DrawEllipse(getX(), getY(), 50, 50, 0.0f, RED, kFillModeSolid);
}

void Enemy::Initialize() {
	enemyPosX = 300;
	enemyPosY = 200;

}

void Enemy::move() {
	enemyPosX += enemySpeed;



	if (enemyPosX < 0) {
		enemySpeed *= -1;
	}

	if (enemyPosX > 1280) {
		enemySpeed = -enemySpeed;
	}
}