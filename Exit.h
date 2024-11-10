#pragma once

#include "raylib.h"
#include "Player.h"
class Exit
{
private:
	float mBrickX = 0;
	float mBrickY = 100;
	float mBrickSize = 50;

public:

	bool mBlockHere = false;
	bool mBlockHIDE = false;
	Exit();
	bool Update(Player player);
	void Draw();
	void Start(int column, int row);
};
