#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#define BLACK 0 #define BLUE 1 #define GREEN 2 #define CYAN 3 #define RED 4 #define MAGENTA 5 #define BROWN 6 #define LIGHTGRAY 7 #define DARKGRAY 8 #define LIGHTBLUE 9 #define LIGHTGREEN 10 #define LIGHTCYAN 11 #define LIGHTRED 12 #define LIGHTMAGENTA 13 #define YELLOW 14 #define WHITE 15 
using namespace std;
//�δ���
/*
" ___ "
" |a| "
"_| |_"  _____  //�⺻ ��
*/

void textcolor(int foreground, int background)
{
    int color = foreground + background * 16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void SetConsoleView()
{
    system("mode con:cols=40 lines=13");
    system("title MOLE CATCHING");
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

void DrawMap()
{
    gotoXY(0, 0);
    for (int i = 0; i < 12; i++)
    {
        cout << gameMap[i] << endl;
    }

    //�ӽ� �δ��� �׷�����
    /*for (int i = 0; i < 3; i++)
    {
        gotoXY(5, i + 2);
        cout << mole[i];
    }*/
}
class Mole
{
private:
    //int moleNum;    //���° �δ�������
    int holeNum;    //���° ���ۿ� �ִ���
    bool isRed;    //�Ķ����ΰ� �������ΰ� (true�� red)
    char key;   //� Ű�� ������ �ϴ°�

public:
    //�δ��� ����
    void createMole()
    {
        setHoleNum();
        drawMole();
        setColor();
    }
    //���� ��ȣ ���
    int getHoleNum()
    {
        return holeNum;
    }
    //���� ���ϱ�
    void setHoleNum()
    {
        holeNum = rand() % 8 + 1;
        //��ġ�� �ʰ� �ϱ�
    }
    //�� ���ϱ�
    void setColor()
    {
        isRed = rand() % 2;
    }
    //�δ��� �׸���
    void drawMole()
    {
        if (isRed)
        {
            textcolor(4, 0);
        }
        else
        {
            textcolor(1, 0);
        }
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
                gotoXY(5 + (holeNum % - 5) * 9, i + 6);
                cout << mole[i];
            }
        }
        if (isRed)
        {
            textcolor(15, 0);
        }
        else
        {
            textcolor(15, 0);
        }
        
    }
    //�δ��� ����
    void deleteMole()
    {
        if (holeNum < 5)
        {
            for (int i = 0; i < 3; i++)
            {
                gotoXY(5 + (holeNum - 1) * 9, i + 2);
                cout << hole[i];
            }
        }
        else if(holeNum > 4)
        {
            for (int i = 0; i < 3; i++)
            {
                gotoXY(5 + (holeNum - 5) * 9, i + 6);
                cout << hole[i];
            }
        }
    }
    //�δ��� �̹� ���� �ִ��� Ȯ���ϱ�

};

Mole* mole1 = new Mole();

void getKeyDown()
{
    char key;
    int num;
    if (_kbhit() != 0)
    {
        key = _getch();
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
        }
        if (mole1->getHoleNum() == num)
        {
            mole1->deleteMole();
            mole1->createMole();
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    cursorVisible(false);
    SetConsoleView();

    DrawMap();

    mole1->createMole();
    while (true)
    {
        getKeyDown();

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
