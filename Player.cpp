#include "Player.h"
Player::Player()
{

}
void Player::Start()
{
	mPlayerSpeed = 2;
	mNbLife = 3;

	mPlayerX = 60;
	mPlayerY = 155;
	mPlayerSizeX = 30;
	mPlayerSizeY = 40;
	mCanGoRight = true;
	mCanGoLeft = true;
	mCanGoUp = true;
	mCanGoDown = true;
}
void Player::Update()
{
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
	{
		if (mPlayerX > 52 && mCanGoLeft == true)
		{
			mPlayerX -= mPlayerSpeed;
		}
	}
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
	{
		if (mPlayerX + mPlayerSizeX < GetScreenWidth() - 52 && mCanGoRight == true)
		{
			mPlayerX += mPlayerSpeed;
		}
	}
	if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
	{
		if (mPlayerY > 152 && mCanGoUp == true)
		{
			mPlayerY -= mPlayerSpeed;
		}
	}
	if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
	{
		if (mPlayerY + mPlayerSizeY < GetScreenHeight() -52 && mCanGoDown == true)
		{
			mPlayerY += mPlayerSpeed;
		}
	}
}
void Player::Draw(Font ft)
{
	DrawTextEx(ft, TextFormat("Left : %01i", mNbLife), Vector2{ (float) GetScreenWidth() - 250,25 }, 60, 5, WHITE);

	//DrawRectangle(mPlayerX, mPlayerY, mPlayerSizeX, mPlayerSizeY, LIME);//hitbox

	DrawRectangle(mPlayerX, mPlayerY+11, mPlayerSizeX, mPlayerSizeY-25, WHITE);//arms
	DrawRectangle(mPlayerX+7, mPlayerY + 31, 6, mPlayerSizeY - 30, WHITE);//left leg
	DrawRectangle(mPlayerX+17, mPlayerY + 31, 6, mPlayerSizeY - 30, WHITE);//right leg
	DrawRectangle(mPlayerX, mPlayerY + 26, mPlayerSizeX, 5, ORANGE);//hands
	DrawRectangle(mPlayerX + 5, mPlayerY + 13, mPlayerSizeX - 10, mPlayerSizeY - 22, BLACK);
	DrawRectangle(mPlayerX+5, mPlayerY + 11, mPlayerSizeX -10, mPlayerSizeY - 22, SKYBLUE);//body
	DrawRectangle(mPlayerX+8, mPlayerY, 14, 11, ORANGE);//head
	DrawRectangle(mPlayerX + 12, mPlayerY +3, 2, 5, BLACK);//left eye
	DrawRectangle(mPlayerX + 12, mPlayerY + 3, 1, 2, WHITE);
	DrawRectangle(mPlayerX + 17, mPlayerY + 3, 2, 5, BLACK);//right eye
	DrawRectangle(mPlayerX + 17, mPlayerY + 3, 1, 2, WHITE);
}

bool Player::LooseLife()
{
	mNbLife -= 1;
	mPlayerX = 60;
	mPlayerY = 155;
	if (mNbLife <= 0) 
	{
		return false;
	}
}
