#include "IndestructibleBlock.h"
IndestructibleBlock::IndestructibleBlock()
{

}
int IndestructibleBlock::Update(Player player, Bomb bomb)
{
	if (mBlockHere == true && player.mPlayerX <= mBrickX + 50 && player.mPlayerX + player.mPlayerSizeX >= mBrickX && player.mPlayerY <= mBrickY + 50 && player.mPlayerY + player.mPlayerSizeY >= mBrickY)
	{
		if (player.mPlayerX < mBrickX + 50 && player.mPlayerX > mBrickX + 40)
		{
			//DrawText("R", 50, 150, 20, WHITE);
			return 1;
		}
		else if (player.mPlayerX + player.mPlayerSizeX < mBrickX + 10 && player.mPlayerX + player.mPlayerSizeX > mBrickX)
		{
			//DrawText("L", 50, 150, 20, WHITE);
			
			return 2;
		}
		else if (player.mPlayerY < mBrickY + 50 && player.mPlayerY < mBrickY + 40)
		{
			//DrawText("D", 50, 150, 20, WHITE);
			
			return 3;
		}
		else if (player.mPlayerY + player.mPlayerSizeY > mBrickY && player.mPlayerY + player.mPlayerSizeY > mBrickY +10)
		{
			//DrawText("U", 50, 150, 20, WHITE);
			return 4;
		}
	}

	if (mBlockHere == true && bomb.mBombExplose == true)
	{
		if (bomb.mBombX - bomb.mBombExplosionRadiusL >= mBrickX && bomb.mBombX - bomb.mBombExplosionRadiusL <= mBrickX + 50 && bomb.mBombY - 15 <= mBrickY + 50 && bomb.mBombY + 15 >= mBrickY)
		{
			//L
			return 5;
		}
		else if (bomb.mBombX + bomb.mBombExplosionRadiusR >= mBrickX && bomb.mBombX - bomb.mBombExplosionRadiusD <= mBrickX + 50 && bomb.mBombY - 15 <= mBrickY + 50 && bomb.mBombY + 15 >= mBrickY)
		{
			//R
			return 6;
		}
		else if (bomb.mBombY + bomb.mBombExplosionRadiusD >= mBrickY && bomb.mBombY - bomb.mBombExplosionRadiusD <= mBrickY + 50 && bomb.mBombX - 15 <= mBrickX + 50 && bomb.mBombX + 15 >= mBrickX)
		{
			//D
			return 7;
		}
		else if (bomb.mBombY + bomb.mBombExplosionRadiusU >= mBrickY && bomb.mBombY - bomb.mBombExplosionRadiusU <= mBrickY + 50 && bomb.mBombX - 15 <= mBrickX + 50 && bomb.mBombX + 15 >= mBrickX)
		{
			//U
			return 8;
		}
	}
}
void IndestructibleBlock::Draw()
{
	if (mBlockHere == true)
	{
		DrawRectangle(mBrickX, mBrickY, 50, 50, BLACK);
		DrawRectangle(mBrickX, mBrickY, 45, 45, LIGHTGRAY);
		DrawRectangle(mBrickX + 5, mBrickY + 5, 40, 40, GRAY);
	}
}
void IndestructibleBlock::Start(int column, int row)
{
	mBrickX += 50 * column;
	mBrickY += 50 * row;
	if (row == 0 || row == 14)
	{
		mBlockHere = true;
	}
	else if (column == 0 || column == 24)
	{
		mBlockHere = true;
	}
	else if ((column == 2 && row == 2) || (column == 4 && row == 2) || (column == 6 && row == 2) || (column == 8 && row == 2) || (column == 10 && row == 2) || (column == 12 && row == 2) || (column == 14 && row == 2) || (column == 16 && row == 2) || (column == 18 && row == 2) || (column == 20 && row == 2) || (column == 22 && row == 2))
	{
		mBlockHere = true;
	}
	else if ((column == 2 && row == 4) || (column == 4 && row == 4) || (column == 6 && row == 4) || (column == 8 && row == 4) || (column == 10 && row == 4) || (column == 12 && row == 4) || (column == 14 && row == 4) || (column == 16 && row == 4) || (column == 18 && row == 4) || (column == 20 && row == 4) || (column == 22 && row == 4))
	{
		mBlockHere = true;
	}
	else if ((column == 2 && row == 6) || (column == 4 && row == 6) || (column == 6 && row == 6) || (column == 8 && row == 6) || (column == 10 && row == 6) || (column == 12 && row == 6) || (column == 14 && row == 6) || (column == 16 && row == 6) || (column == 18 && row == 6) || (column == 20 && row == 6) || (column == 22 && row == 6))
	{
		mBlockHere = true;
	}
	else if ((column == 2 && row == 8) || (column == 4 && row == 8) || (column == 6 && row == 8) || (column == 8 && row == 8) || (column == 10 && row == 8) || (column == 12 && row == 8) || (column == 14 && row == 8) || (column == 16 && row == 8) || (column == 18 && row == 8) || (column == 20 && row == 8) || (column == 22 && row == 8))
	{
		mBlockHere = true;
	}
	else if ((column == 2 && row == 10) || (column == 4 && row == 10) || (column == 6 && row == 10) || (column == 8 && row == 10) || (column == 10 && row == 10) || (column == 12 && row == 10) || (column == 14 && row == 10) || (column == 16 && row == 10) || (column == 18 && row == 10) || (column == 20 && row == 10) || (column == 22 && row == 10))
	{
		mBlockHere = true;
	}
	else if ((column == 2 && row == 12) || (column == 4 && row == 12) || (column == 6 && row == 12) || (column == 8 && row == 12) || (column == 10 && row == 12) || (column == 12 && row == 12) || (column == 14 && row == 12) || (column == 16 && row == 12) || (column == 18 && row == 12) || (column == 20 && row == 12) || (column == 22 && row == 12))
	{
		mBlockHere = true;
	}
}