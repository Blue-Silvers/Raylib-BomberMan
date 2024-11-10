#pragma once
#include "raylib.h"
#include "Player.h"
#include "Bomb.h"
class IndestructibleBlock
{
private:
	float mBrickX = 0;
	float mBrickY = 100;

public:
	
	bool mBlockHere = false;
	IndestructibleBlock();
	int Update(Player player, Bomb bomb);
	void Draw();
	void Start(int column, int row);
};

