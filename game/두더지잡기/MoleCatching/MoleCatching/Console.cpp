#include "Console.h"

#include <iostream>

using namespace std;

void textcolor(int foreground, int background)
{
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoXY(int x, int y)
{
    COORD cur;
    cur.X = x;
    cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

void cursorVisible(bool b)
{
    static HANDLE hOut;
    CONSOLE_CURSOR_INFO cInfo;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    cInfo.dwSize = 100;
    cInfo.bVisible = b;
    SetConsoleCursorInfo(hOut, &cInfo);
}

int getKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }

    return 0;
}