#include "Exit.h"
Exit::Exit()
{
	mBrickX = 0;
	mBrickY = 100;

}
bool Exit::Update(Player player)
{
	if (mBlockHere == true && player.mPlayerX <= mBrickX + 30 && player.mPlayerX + player.mPlayerSizeX >= mBrickX + 20 && player.mPlayerY <= mBrickY + 30 && player.mPlayerY + player.mPlayerSizeY >= mBrickY+20)
	{
		return true;
	}
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
	{
		if (mBlockHIDE == true)
		{
			mBlockHIDE = false;
			mBrickSize = 50;
		}
		else 
		{
			mBlockHIDE = true;
			mBrickSize = 60;
		}
	}
}
void Exit::Draw()
{

	if (mBlockHere == true)
	{
		DrawRectangle(mBrickX, mBrickY, mBrickSize, mBrickSize, BLUE);
	}
	else 
	{
		mBrickX = 0;
		mBrickY = 100;
	}
}
void Exit::Start(int column, int row)
{
	mBrickX = 0;
	mBrickY = 100;
	if (mBlockHere == false) 
	{
		mBrickX += 50 * column;
		mBrickY += 50 * row;
		mBlockHere = true;
	}
}