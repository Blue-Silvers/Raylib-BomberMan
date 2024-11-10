#include "raylib.h"
#include "IndestructibleBlock.h"
#include "Brick.h"
#include "Player.h"
#include "Bomb.h"
#include "Timer.h"
#include "Menus.h"
#include "Exit.h"
#include <iostream>

using namespace std;

void Start();
void ReStart();
void Update();
void Draw();
void End();

int score = 0;
int blocks, newBlocksNb = 0;

int column = 10;
int row = 5;

int test1, test2 = 0;

Font ft;
Vector2 textPos{ GetScreenWidth() / 5, GetScreenHeight() / 2.5 };
Vector2 scorePos{ GetScreenWidth() / 5, 20 };

IndestructibleBlock indestructibleBlock[25][15];
Brick bricks[25][15];
Player player;
Bomb bomb;
Timer timer;
Menus menus;
Exit newExit;

int main() {

    Start();

    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    End();
    return 0;
}


void Start()
{
    InitWindow(1250, 850, "Bomberman !");
    SetTargetFPS(60);
    ft = LoadFont("resources/fonts/jupiter_crash.png");
    column = 25;
    row = 15;
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            indestructibleBlock[i][j].Start(i, j);
        }
    }
    menus.Start(ft);
}

void ReStart()
{
    textPos.x = GetScreenWidth() / 5;
    textPos.y = GetScreenHeight() / 2.5;
    scorePos.x = GetScreenWidth() / 2.3;
    scorePos.y = 25;
    score = 0;
    blocks = 0;
    newBlocksNb = 0;
    newExit.mBlockHere = false;
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (indestructibleBlock[i][j].mBlockHere == false)
            {
                int random = rand() % 99;
                if (random <= 38)
                {
                    if (bricks[i][j].Start(i, j) == false)
                    {
                        blocks += 1;
                        newBlocksNb += 1;
                        int random = rand() % 50;
                        if (random == 0)
                        {
                            newExit.Start(i, j);
                            //spawn end
                        }
                    }
                }
            }
        }
    }
    player.Start();
    bomb.Start();
    timer.Start();
}

void Update()
{
    if (menus.Update() == 1)
    {
        ReStart();
    }
    else if (menus.Update() == 2)
    {
        End();
    }

    if (bomb.Update(player) == 1) 
    {
        if (player.LooseLife() == false) 
        {
            menus.Die();
        }
    }

    player.mCanGoLeft = true;
    player.mCanGoRight = true;
    player.mCanGoUp = true;
    player.mCanGoDown = true;

    newBlocksNb = 0;
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            test1 = indestructibleBlock[i][j].Update(player, bomb);
            
            if (bricks[i][j].mBlockHere == true)
            {
                test2 = bricks[i][j].Update(player, bomb);
                newBlocksNb += 1;
            }

            if (test1 == 1 || test2 == 1)
            {
                player.mCanGoLeft = false;
            }
            else if (test1 == 2 || test2 == 2)
            {
                player.mCanGoRight = false;
            }
            else if (test1 == 3 || test2 == 3)
            {
                player.mCanGoDown = false;
            }
            else if (test1 == 4 || test2 == 4)
            {
                player.mCanGoUp = false;
            }

            if (test1 == 5)
            {
                bomb.mCanGoLeft = false;
            }
            if (test1 == 6)
            {
                bomb.mCanGoRight = false;
            }
            if (test1 == 7)
            {
                bomb.mCanGoDown = false;
            }
            if (test1 == 8)
            {
                bomb.mCanGoUp = false;
            }

            if (test2 == 5) 
            {
                if (score == (blocks -2) * 100)
                {
                    newExit.Start(i, j);
                }
            }
        }
    }
    score = (blocks - newBlocksNb) * 100;

    player.Update();

    if (newExit.Update(player) == true)
    {
        timer.Pause();
        menus.GameOver();
        newExit.mBlockHere = false;
    }

    timer.Update();
}

void Draw()
{
    BeginDrawing();

    ClearBackground(DARKGREEN);
    DrawRectangle(0, 0, GetScreenWidth(), 100, GRAY);

    newExit.Draw();

    player.Draw(ft);

    if (bomb.mBombPose == true) 
    {
        bomb.Draw();
    }

    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            indestructibleBlock[i][j].Draw();
            if (bricks[i][j].mBlockHere == true)
            {
                bricks[i][j].Draw(i, j);
            }
        }
    }



    DrawTextEx(ft, TextFormat("%08i", score), scorePos, 60, 5, WHITE);
    timer.Draw(ft);
    menus.Draw(timer.mGetMinute, timer.mGetSecond, score);

    EndDrawing();
}

void End()
{
    CloseWindow();
}