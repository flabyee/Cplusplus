#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <vector>
#include <algorithm>

#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#include <fstream>

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

int life = 3;
int score = 0;

int gameSpeed = 100;

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
    cout << "SCORE : " <<score << "     ";


    gotoXY(32, 13);
    cout << "        ";
    gotoXY(32, 13);
    for (int i = 0; i < life; i++)
    {
        cout << "♡";
    }

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

    ifstream fin;
    ofstream fout;



    srand((unsigned)time(NULL));
    cursorVisible(false);
    SetConsoleView();

    DrawMap();



    while (true)
    {
        // mole 생성
        if ((rand() % 100 < 20) && moles.size() < 5)
        {
            Mole mole;
            mole.initMole();
            setHoleNum(&mole);
            mole.drawMole();
            moles.push_back(mole);
        }

        // mole 잡기
        key = getKeyDown();
        key = tolower(key);
        score--;

        if(key == 0)
        {
            score++;
        }

        for (int i = 0; i < (int)moles.size(); i++)
        {
            if (moles[i].compareKey(key))
            {
                if (moles[i].getIsFake()) 
                { 
                    score -= 4; 
                    PlaySound(TEXT("not.wav"), NULL, SND_ASYNC);
                    life--;
                }
                else 
                {
                    score += 2;
                    PlaySound(TEXT("right.wav"), NULL, SND_ASYNC);
                    if (gameSpeed > 30)  gameSpeed--;
                }

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

        Sleep(gameSpeed);

        gotoXY(20, 10);
        drawUI();

        if (life < 0)
        {
            break;
        }
    }

    system("cls");
    gotoXY(15, 5);
    cout << "GAME OVER!";
    gotoXY(12, 7);
    cout << "당신의 점수는 " << score;
    gotoXY(10, 9);
    cout << "아무 키나 눌러주세요";
    _getch();

    //DrawMap();
    //for (int i = 0; i < 3; i++)
    //{
    //    gotoXY(14, i + 6);
    //    cout << mole[i];
    //}

    //int a = 0;
    //cin >> a;
}
