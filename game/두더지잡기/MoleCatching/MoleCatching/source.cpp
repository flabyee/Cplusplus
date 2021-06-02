#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <vector>
#define BLACK 0 #define BLUE 1 #define GREEN 2 #define CYAN 3 #define RED 4 #define MAGENTA 5 #define BROWN 6 #define LIGHTGRAY 7 #define DARKGRAY 8 #define LIGHTBLUE 9 #define LIGHTGREEN 10 #define LIGHTCYAN 11 #define LIGHTRED 12 #define LIGHTMAGENTA 13 #define YELLOW 14 #define WHITE 15 
using namespace std;

#include "Console.h"
#include "Mole.h"

//두더지
/*
" ___ "
" |a| "
"_| |_"  _____  //기본 땅
*/


void SetConsoleView()
{
    system("mode con:cols=40 lines=13");
    system("title MOLE CATCHING");
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


void DrawMap()
{
    gotoXY(0, 0);
    for (int i = 0; i < 12; i++)
    {
        cout << gameMap[i] << endl;
    }

    //임시 두더지 그려보기
    /*for (int i = 0; i < 3; i++)
    {
        gotoXY(5, i + 2);
        cout << mole[i];
    }*/
}


Mole mole1;

void catchMole()
{
    char key;
    int num;
    
    key = getKeyDown();
    key = tolower(key);
    switch (key)
    {
    case 'q':
        num = 1;
        break;
    case 'w':
        num = 2;
        break;
    case 'e':
        num = 3;
        break;
    case 'r':
        num = 4;
        break;
    case 'a':
        num = 5;
        break;
    case 's':
        num = 6;
        break;
    case 'd':
        num = 7;
        break;
    case 'f':
        num = 8;
        break;
    default:
        num = 0;
        break;
    }

    
    if (mole1.getHoleNum() == num)
    {
        mole1.deleteMole();
        mole1.initMole();
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cursorVisible(false);
    SetConsoleView();

    DrawMap();

    mole1.initMole();
    mole1.drawMole();
    while (true)
    {
        catchMole();

        gotoXY(20, 10);
    }











    //DrawMap();
    //for (int i = 0; i < 3; i++)
    //{
    //    gotoXY(14, i + 6);
    //    cout << mole[i];
    //}

    //int a = 0;
    //cin >> a;
}
