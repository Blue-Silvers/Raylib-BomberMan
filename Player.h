#pragma once
#include "raylib.h"
class Player
{
private:

	float mPlayerSpeed = 2;
	int mNbLife = 3;

public:
	float mPlayerX = 60;
	float mPlayerY = 155;
	float mPlayerSizeX = 30;
	float mPlayerSizeY = 40;
	bool mCanGoRight = true;
	bool mCanGoLeft = true;
	bool mCanGoUp = true;
	bool mCanGoDown = true;
	Player();
	void Update();
	void Draw(Font ft);
	void Start();
	bool LooseLife();
};

