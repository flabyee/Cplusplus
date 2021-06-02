#include "Mole.h"
#include "Console.h"

#include <iostream>
using namespace std;

int Mole::num = 1;

void Mole::initMole()
{
    //setHoleNum();
    //drawMole();
    //setColor();

    isFake = rand() % 2;
    //���߿� Ȯ�� ����

    key = rand() % 26 + 97; //97(a)~122(z)

    life = 15;

    moleNum = Mole::num++;
}

int Mole::getHoleNum()
{
    return holeNum;
}

char Mole::getKey()
{
    return key;
}

int Mole::getMoleNum()
{
    return moleNum;
}

bool Mole::getIsFake()
{
    return isFake;
}

void Mole::drawMole()
{
    //�� �ٲٱ�(isRed�� ����)
    
    //�׸���
    if (holeNum < 5)
    {
        for (int i = 0; i < 3; i++)
        {
            gotoXY(5 + (holeNum - 1) * 9, i + 2);

            textcolor(9);
            cout << mole[i];
            textcolor(15);
        }


        if (isFake)
        {
            textcolor(1);
            gotoXY(5 + (holeNum - 1) * 9 + 1, 2);
            cout << '$';
            textcolor(15);
        }

        gotoXY(5 + (holeNum - 1) * 9 + 1, 3);
        cout << key;
    }
    else if (holeNum > 4)
    {
        for (int i = 0; i < 3; i++)
        {
            gotoXY(5 + (holeNum % -5) * 9, i + 6);

            textcolor(9);
            cout << mole[i];
            textcolor(15);


        }

        gotoXY(5 + (holeNum % -5) * 9 + 1, 7);
        cout << key;

        
        if (isFake)
        {
            textcolor(1);
            gotoXY(5 + (holeNum % -5) * 9 + 1, 6);
            cout << '$';
            textcolor(15);
        }
    }
    


}

void Mole::deleteMole()
{
    //�ٽ� �������� �׸���
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
}

void Mole::setHoleNum(int value)
{
    holeNum = value;
}

bool Mole::isEnd()
{
    if (life > 0)
    {
        life--;
        return false;
    }
    else
    {
        return true;
    }

}

bool Mole::compareKey(char _key)
{
    if (key == _key)    return true;
                        return false;
}