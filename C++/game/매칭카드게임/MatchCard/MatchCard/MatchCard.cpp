#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

void gotoxy(int x, int y)
{
    HANDLE hOut;
    COORD Cur;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(hOut, Cur);
}

int main()
{
    
    srand((unsigned)time(NULL));
    int num[20] = { 0,};
    
    //2번째 방법
    int index = 1;
    for (int i = 0; i < 20; i++)
    {
        num[i] = -1;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            do {
                index = rand() % 20;
            }while(num[index] != -1);   //true -> num[index] != -1
                                        //false -> num[index] == -1
            num[index] = i; 
        }
    }

    //첫번째 방법
    //int sameNum = 0;
    //bool bSame = false;
    //for (int i = 0; i < 20; i++)
    //{
    //    do {
    //        sameNum = 0;
    //        //bSame = false;

    //        num[i] = rand() % 10;

    //        if (i > 1)
    //        {
    //            for (int j = 0; j < i; j++)
    //            {
    //                if (num[i] == num[j])
    //                {
    //                    sameNum++;
    //                }
    //            }

    //            /*if (sameNum > 1)
    //            {
    //                bSame = true;
    //            }*/
    //        }
    //    } while (sameNum > 1);

    //}

    for (int i = 0; i < 20; i++)
    {
        gotoxy(i % 5, i / 5);
        cout << num[i];
    }

    Sleep(3000);

    for (int i = 0; i < 20; i++)
    {
        gotoxy(i % 5, i / 5);
        cout << '*';
    }

    char keyCode[20] = {
        '1', '2', '3', '4', '5',
        'q', 'w', 'e', 'r', 't',
        'a', 's', 'd', 'f', 'g',
        'z', 'x', 'c', 'v', 'b'
    };

    int selectIndex[2] = { 0, };
    int check = 0;

    int key;

    while (true)
    {
        key = _getch();
        for (int i = 0; i < 20; i++)
        {
            if (key == keyCode[i] && num[i] != -1)
            {
                selectIndex[check] = i;

                gotoxy(i % 5, i / 5);
                cout << num[i];

                check++;
                
                break;
            }          
        }

        

        if (check == 2)
        {
            if (selectIndex[0] == selectIndex[1])
            {
                gotoxy(selectIndex[0] % 5, selectIndex[0] / 5);
                cout << '*';
                check = 0;
                continue;
            }

            if (num[selectIndex[0]] != num[selectIndex[1]])
            {
                Sleep(1000);

                for (int i = 0; i < 2; i++)
                {
                    gotoxy(selectIndex[i] % 5, selectIndex[i] / 5);
                    cout << '*';
                }
                
            }
            else //같을 때
            {
                num[selectIndex[0]] = -1;
                num[selectIndex[1]] = -1;
            }

            check = 0;
        }
    }
    
    return 0;

}