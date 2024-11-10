#pragma once
#include "raylib.h"
class Menus
{
private:
	Font mFt;
	bool mMenuOpen = true;
	bool mGameOver = false;

public:
	Menus();
	int Update();
	void Draw(float minute, float second, int score);
	void Start(Font ft);
	void GameOver();
	void Die();
};