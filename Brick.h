#pragma once
#include "raylib.h"
#include "Player.h"
#include "Bomb.h"
class Brick
{
private:
	float mBrickX = 0;
	float mBrickY = 100;

public:

	bool mBlockHere = false;
	Brick();
	int Update(Player player, Bomb bomb);
	void Draw(int column, int row);
	bool Start(int column, int row);
};

