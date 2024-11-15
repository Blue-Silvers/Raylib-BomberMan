#include "Timer.h"

Timer::Timer()
{
    mSecond = 0;
    mMinute = 0;
    mStopTimer = false;

}
void Timer::Start()
{
    mSecond = 0;
    mMinute = 0;
    mStopTimer = false;
}
void Timer::Update()
{
    if (mStopTimer == false)
    {
        mSecond += GetFrameTime();
        if (mSecond >= 59)
        {
            mSecond = 0;
            mMinute += 1;
        }
    }

}
void Timer::Draw(Font ft)
{
    DrawTextEx(ft, TextFormat("%02.02f min", /*GetTime() / 100)*/mMinute + mSecond / 100), Vector2{ 100,25 }, 60, 5, WHITE);
}

void Timer::Pause()
{
    mStopTimer = true;
    mGetMinute = mMinute;
    mGetSecond = mSecond;
}
