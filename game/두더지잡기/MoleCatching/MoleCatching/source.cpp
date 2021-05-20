#include <iostream>
#include <conio.h>
#include <Windows.h>
#define BLACK 0 #define BLUE 1 #define GREEN 2 #define CYAN 3 #define RED 4 #define MAGENTA 5 #define BROWN 6 #define LIGHTGRAY 7 #define DARKGRAY 8 #define LIGHTBLUE 9 #define LIGHTGREEN 10 #define LIGHTCYAN 11 #define LIGHTRED 12 #define LIGHTMAGENTA 13 #define YELLOW 14 #define WHITE 15 
using namespace std;
//두더지
/*
" ___ "
" |a| "
"_| |_"  _____  //기본 땅
*/

void textcolor(int foreground, int background)
{
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void SetConsoleView()
{
    system("mode con:cols=40 lines=16");
    system("title WORD GAME");
}
void gotoXY(int x, int y)
{
    COORD cur;
    cur.X = x;
    cur.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}
char gameMap[12][41] =
{
    "++++++++++++++++++++++++++++++++++++++++",
    "+                                      +",
    "+                                      +",
    "+                                      +",
    "+   _____    _____    _____    _____   +",
    "+                                      +",
    "+                                      +",
    "+                                      +",
    "+   _____    _____    _____    _____   +",
    "+                                      +",
    "+                                      +",
    "++++++++++++++++++++++++++++++++++++++++"
};
char mole[3][4] =
{
    "___",
    "| |",
    "| |"
};
char hole[3][4] =
{
    "   ",
    "   ",
    "___"
};

void ShowMap()
{
    gotoXY(0, 0);
    for (int i = 0; i < 12; i++)
    {
        cout << gameMap[i] << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        gotoXY(5, i + 2);
        cout << mole[i];
    }
}

int main()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.bVisible = FALSE;
    SetConsoleView();
    ShowMap();












    int a;
    cin >> a;
}
