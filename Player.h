#pragma once
class Player
{
private:
	int posX;
	int posY;
	int playerSpeedX;
	int playerSpeedY;

public:
	Player();

	int playerGetX() { return posX; }
	int playerGetY() { return posY; }

	void Draw();

	void move(char keys[]);

	void Initialize();

	void shoot();
};
