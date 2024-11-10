#include "Bomb.h"
Bomb::Bomb()
{

}
void Bomb::Start()
{
	mBombColor = DARKGRAY;
	mBombDuration = mBombTime;
	mBombExplose = false;
	mBombPose = false;
}
int Bomb::Update(Player player/*float playerX, float playerY, float playerSizeX, float playerSizeY*/)
{
	if (mBombPose == false) 
	{
		if (IsKeyDown(KEY_SPACE))
		{
			mBombPose = true;
			Pose(player.mPlayerX, player.mPlayerY, player.mPlayerSizeX, player.mPlayerSizeY);
		}
	}
	else if (mBombExplose == false)
	{
		mDelay += GetFrameTime();
		if(mDelay >= 0.5)
		{
			mDelay = 0;
			mBombDuration -= 0.5;
			if (mBombDuration != (int)mBombDuration) 
			{
				mBombColor = GRAY;
				mBombSize += 2;
			}
			else
			{
				mBombColor = DARKGRAY;
				mBombSize -= 2;
			}

			if (mBombDuration <= 0) 
			{
				mBombExplose = true;
				mDelay = 0;
				mBombDuration = mBombTime;
			}
		}
	}
	else if (mBombExplose == true) 
	{
		mDelay += GetFrameTime();
		if (mDelay >= 1) 
		{
			mBombExplose = false;
			mBombPose = false;
			mBombExplosionRadiusR = 1;
			mBombExplosionRadiusL = 1;
			mBombExplosionRadiusU = 1;
			mBombExplosionRadiusD = 1;
			mCanGoRight = true;
			mCanGoLeft = true;
			mCanGoUp = true;
			mCanGoDown = true;
		}
		else {

			//damage
			if (player.mPlayerX <= mBombX + mBombExplosionRadiusR && player.mPlayerX + player.mPlayerSizeX >= mBombX && player.mPlayerY <= mBombY + 15 && player.mPlayerY + player.mPlayerSizeY >= mBombY - 15)
			{
				return 1;
			}
			else if (player.mPlayerX <= mBombX && player.mPlayerX + player.mPlayerSizeX >= mBombX - mBombExplosionRadiusL && player.mPlayerY <= mBombY + 15 && player.mPlayerY + player.mPlayerSizeY >= mBombY - 15)
			{
				return 1;
			}
			if (player.mPlayerY <= mBombY + mBombExplosionRadiusD && player.mPlayerY + player.mPlayerSizeY >= mBombY && player.mPlayerX <= mBombX + 15 && player.mPlayerX + player.mPlayerSizeX >= mBombX - 15)
			{
				return 1;//bug
			}
			else if (player.mPlayerY <= mBombY && player.mPlayerY + player.mPlayerSizeY >= mBombY - mBombExplosionRadiusU && player.mPlayerX <= mBombX + 15 && player.mPlayerX + player.mPlayerSizeX >= mBombX - 15)
			{
				return 1;
			}


			if (mCanGoRight == true)
			{
				mBombExplosionRadiusR += mBombExplosionSpeed;
				if (mBombExplosionRadiusR >= mBombExplosionRadiusMax)
				{
					mBombExplosionRadiusR = mBombExplosionRadiusMax;
					mCanGoRight = false;
				}
			}
			if (mCanGoLeft == true)
			{
				mBombExplosionRadiusL += mBombExplosionSpeed;
				if (mBombExplosionRadiusL >= mBombExplosionRadiusMax)
				{
					mBombExplosionRadiusL = mBombExplosionRadiusMax;
					mCanGoLeft = false;
				}
			}
			if (mCanGoUp == true)
			{
				mBombExplosionRadiusU += mBombExplosionSpeed;
				if (mBombExplosionRadiusU >= mBombExplosionRadiusMax)
				{
					mBombExplosionRadiusU = mBombExplosionRadiusMax;
					mCanGoUp = false;
				}
			}
			if (mCanGoDown == true)
			{
				mBombExplosionRadiusD += mBombExplosionSpeed;
				if (mBombExplosionRadiusD >= mBombExplosionRadiusMax)
				{
					mBombExplosionRadiusD = mBombExplosionRadiusMax;
					mCanGoDown = false;
				}
			}
		}
	}
}
void Bomb::Draw()
{
	//if (mBombPose == true)
	if (mBombExplose == false) 
	{
		DrawCircle(mBombX, mBombY, mBombSize, mBombColor);
		DrawCircleLines(mBombX, mBombY, mBombSize, BLACK);
	}
	else 
	{
		//explose line every direction
		DrawRectangle(mBombX, mBombY - 15, mBombExplosionRadiusR, 30, RED);
		DrawRectangle(mBombX - mBombExplosionRadiusL, mBombY - 15, mBombExplosionRadiusL, 30, RED);
		DrawRectangle(mBombX - 15, mBombY - mBombExplosionRadiusU, 30, mBombExplosionRadiusU, RED);
		DrawRectangle(mBombX - 15, mBombY, 30, mBombExplosionRadiusD, RED);
	}
}

void Bomb::Pose(float playerX, float playerY, float playerSizeX, float playerSizeY)
{
	mBombX = playerX + playerSizeX / 2;
	mBombY = playerY + playerSizeY / 2;
}