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
    //��ġ�� �Ȱ��ϱ�

    isRed = rand() % 2;
    //���߿� Ȯ�� ����
}

int Mole::getHoleNum()
{
    return holeNum;
}

void Mole::drawMole()
{
    //�� �ٲٱ�(isRed�� ����)
    if (isRed)
    {
        textcolor(4, 0);
    }
    else
    {
        textcolor(1, 0);
    }
    //�׸���
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
    //�� ���󺹱�
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