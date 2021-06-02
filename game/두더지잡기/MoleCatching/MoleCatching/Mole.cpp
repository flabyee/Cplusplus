#include "Mole.h"
#include "Console.h"

#include <iostream>
using namespace std;

void Mole::initMole()
{
    //setHoleNum();
    //drawMole();
    //setColor();
    life = 10;

    isAlive = true;

    holeNum = rand() % 8 + 1;
    //겹치지 안게하기

    isRed = rand() % 2;
    //나중에 확률 조정
}

int Mole::getHoleNum()
{
    return holeNum;
}

void Mole::drawMole()
{
    //색 바꾸기(isRed에 따라)
    if (isRed)
    {
        textcolor(4, 0);
    }
    else
    {
        textcolor(1, 0);
    }
    //그리기
    if (holeNum < 5)
    {
        for (int i = 0; i < 3; i++)
        {
            gotoXY(5 + (holeNum - 1) * 9, i + 2);
            cout << mole[i];
        }
    }
    else if (holeNum > 4)
    {
        for (int i = 0; i < 3; i++)
        {
            gotoXY(5 + (holeNum % -5) * 9, i + 6);
            cout << mole[i];
        }
    }
    //색 원상복귀
    if (isRed)
    {
        textcolor(15, 0);
    }
    else
    {
        textcolor(15, 0);
    }


}

void Mole::deleteMole()
{
    //다시 구멍으로 그리기
    if (holeNum < 5)
    {
        for (int i = 0; i < 3; i++)
        {
            gotoXY(5 + (holeNum - 1) * 9, i + 2);
            cout << hole[i];
        }
    }
    else if (holeNum > 4)
    {
        for (int i = 0; i < 3; i++)
        {
            gotoXY(5 + (holeNum - 5) * 9, i + 6);
            cout << hole[i];
        }
    }

    isAlive = false;
}

void Mole::isEnd()
{
    if (life > 0)
    {
        life--;
    }
    else
    {
        deleteMole();
    }

}