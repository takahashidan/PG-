#pragma once
#include "Player.h"

class Bullet {
private:
	int bulletPosX;
	int bulletPosY;
	int bulletSpeed;
	bool isBullet = false;
public:

	Bullet();
	void SetPosition(int x, int y);

	void Initialize();

	int bulletGetX() const { return bulletPosX; }
	int bulletGetY() const { return bulletPosY; }

	void Draw();
	void shot(char keys[], char preKeys[], int x, int y);

	Player player;
};
