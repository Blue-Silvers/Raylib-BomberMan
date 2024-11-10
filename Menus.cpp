#include "Menus.h"

Menus::Menus()
{

}
void Menus::Start(Font ft)
{
    mMenuOpen = true;
    mGameOver = false;
    mFt = ft;
}
int Menus::Update()
{
    if (mMenuOpen == true)
    {
        if (CheckCollisionPointRec(GetMousePosition(), { 420, 395, 300, 75 }))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                mMenuOpen = false;
                SetMouseCursor(MOUSE_CURSOR_DEFAULT);
                return 1;

            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), { 420, 600, 300, 75 }))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                return 2;
            }
        }
        else
        {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }
    }
    else if (mGameOver == true)
    {
        if (CheckCollisionPointRec(GetMousePosition(), { 420, 495, 300, 75 }))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                mGameOver = false;
                SetMouseCursor(MOUSE_CURSOR_DEFAULT);
                return 1;

            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), { 420, 600, 300, 75 }))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                mMenuOpen = true;
                mGameOver = false;
                return 3;
            }
        }
        else if (CheckCollisionPointRec(GetMousePosition(), { 420, 700, 300, 75 }))
        {
            SetMouseCursor(MOUSE_CURSOR_POINTING_HAND);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                return 2;
            }
        }
        else
        {
            SetMouseCursor(MOUSE_CURSOR_DEFAULT);
        }
    }
}
void Menus::Draw(float minute, float second, int score)
{
    if (mMenuOpen == true)
    {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

        DrawTextEx(mFt, "Bomberman", Vector2{ 300, 50 }, 200, 5, WHITE);

        DrawTextEx(mFt, "Start", Vector2{ 510, 400 }, 75, 5, WHITE);
        DrawRectangleLines(420, 395, 300, 75, WHITE);

        DrawTextEx(mFt, "Quit game", Vector2{ 450, 600 }, 75, 5, WHITE);
        DrawRectangleLines(420, 600, 300, 75, WHITE);
    }
    else if (mGameOver == true)
    {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);

        DrawTextEx(mFt, "Congratulation", Vector2{ 200, 50 }, 200, 5, WHITE);

        DrawTextEx(mFt, TextFormat("Your time : %02.02f min", minute + second / 100), Vector2{ 300,250 }, 100, 5, WHITE);

        DrawTextEx(mFt, TextFormat("Your score : %08i", score), Vector2{ 300,350 }, 100, 5, WHITE);

        DrawTextEx(mFt, "Retry", Vector2{ 500, 500 }, 75, 5, WHITE);
        DrawRectangleLines(420, 500, 300, 75, WHITE);

        DrawTextEx(mFt, "Main menu", Vector2{ 445, 600 }, 75, 5, WHITE);
        DrawRectangleLines(420, 600, 300, 75, WHITE);

        DrawTextEx(mFt, "Quit game", Vector2{ 450, 700 }, 75, 5, WHITE);
        DrawRectangleLines(420, 700, 300, 75, WHITE);
    }
}

void Menus::GameOver()
{
    mGameOver = true;
}

void Menus::Die()
{
    mMenuOpen = true;
}