#pragma once
#include "raylib.h"
#include "Player.h"

class Bomb
{
private:
	float mBombTime = 3;
	float mBombDuration = 3;
	Color mBombColor;

	float mBombExplosionRadiusMax = 60;
	float mDelay;
	float mBombExplosionSpeed = 3.5;

public:	
	bool mCanGoRight = true;
	bool mCanGoLeft = true;
	bool mCanGoUp = true;
	bool mCanGoDown = true;
	float mBombX = 50;
	float mBombY = 150;
	float mBombSize = 20;
	bool mBombExplose = false;
	bool mBombPose = false;
	float mBombExplosionRadiusR = 1;
	float mBombExplosionRadiusL = 1;
	float mBombExplosionRadiusU = 1;
	float mBombExplosionRadiusD = 1;

	Bomb();
	void Start();
	int Update(Player player/*float playerX, float playerY, float playerSizeX, float playerSizeY*/);
	//void Explose(float brickX, float brickY);
	void Draw();
	void Pose(float playerX, float playerY, float playerSizeX, float playerSizeY);
};

