#include "Console.h"

#include <iostream>

using namespace std;

void setTextColor(int foreground, int background)
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

void clrscr()
{
    system("cls");
}


int getKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }

    return 0;
}

void setNoCursor()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}