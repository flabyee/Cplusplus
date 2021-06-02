#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <vector>
#include <algorithm>
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

vector<Mole> moles;

int score = 0;

void SetConsoleView()
{
    system("mode con:cols=40 lines=16");
    system("title MOLE CATCHING");

    moles.clear();  
}

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

void drawUI()
{
    gotoXY(0, 13);
    cout << "SCORE : " <<score << "                       ";
}

void setHoleNum(Mole* mole)
{
    bool bCheck = false;

    do {
        bCheck = false;

        mole->setHoleNum(rand() % 8 + 1);

        for (int i = 0; i < (int)moles.size(); i++)
        {
            if ((mole->getHoleNum() == moles[i].getHoleNum()) && (mole->getMoleNum() != moles[i].getMoleNum()))
            {
                bCheck = true;
            }
        }
    } while (bCheck);

}


int main()
{
    char key = '1';

    srand((unsigned)time(NULL));
    cursorVisible(false);
    SetConsoleView();

    DrawMap();



    while (true)
    {
        if ((rand() % 100 < 10) && moles.size() < 5)
        {
            Mole mole;
            mole.initMole();
            setHoleNum(&mole);
            mole.drawMole();
            moles.push_back(mole);
        }


        key = getKeyDown();
        key = tolower(key);

        for (int i = 0; i < (int)moles.size(); i++)
        {
            if (moles[i].compareKey(key))
            {
                if (moles[i].getIsRed())    score--;
                else                        score++;
                moles[i].deleteMole();
                moles.erase(moles.begin() + i);
                i--;
            }
        }

        for (int i = 0; i < (int)moles.size(); i++)
        {
            if (moles[i].isEnd())
            {
                moles[i].deleteMole();
                moles.erase(moles.begin() + i);
                i--;
            }
        }

        Sleep(100);
        gotoXY(20, 10);
        drawUI();
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
