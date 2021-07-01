#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>
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

char menu[12][41] =
{
    "++++++++++++++++++++++++++++++++++++++++",
    "+                                      +",
    "+                                      +",
    "+                                      +",
    "+                                      +",
    "+                                      +",
    "+                                      +",
    "+                                      +",
    "+                                      +",
    "+                                      +",
    "+                                      +",
    "++++++++++++++++++++++++++++++++++++++++"
};

vector<Mole> moles;

float score;

float gameSpeed;

char key;

bool isRight;
bool isStart;

int highScore[5];

void SetConsoleView()
{
    system("mode con:cols=40 lines=16");
    system("title MOLE CATCHING");

    moles.clear();  
}

void initData()
{
    score = 0;

    gameSpeed = 80;

    key = '1';

    isRight = true;
    isStart = false;
}

void DrawMap()
{
    system("cls");

    gotoXY(0, 0);
    for (int i = 0; i < 12; i++)
    {
        cout << gameMap[i] << endl;
    }
}

void drawMenu()
{
    system("cls");

    gotoXY(0, 0);
    for (int i = 0; i < 12; i++)
    {
        cout << menu[i] << endl;
    }

    gotoXY(13, 2);
    cout << "$두더지 잡기#";

    gotoXY(14, 4);
    cout << "HIGH SCORE!";

    for (int i = 0; i < 5; i++)
    {
        gotoXY(15, 6 + i);
        cout << i + 1 << " : " << highScore[i];
    }



    gotoXY(0, 14);
    cout << "종료[x]    [s]를 눌러서 시작    설명[o]";
}

void drawEnd()
{
    system("cls");
    gotoXY(15, 5);
    cout << "GAME END";
    gotoXY(12, 7);
    cout << "당신의 점수는 " << score;
    gotoXY(10, 9);
    cout << "아무 키나 눌러주세요";
    _getch();
}

void drawUI()
{
    gotoXY(0, 13);
    cout << "SCORE : " << score << "                ";

    gotoXY(32, 13);
    cout << "        ";
    gotoXY(26, 13);
    cout << "SPEED : " << gameSpeed << "  ";
    gotoXY(0, 14);
    cout << " ";

}

void drawManual()
{
    system("cls");

    gotoXY(0, 1);
    
    cout << "두더지 몸에 알파벳과 같은 키를 누르면 두더지를 잡을 수 있습니다.(+1점)" << endl << endl;
    cout << "다른 키를 누르면 -1점" << endl << endl;
    cout << "또한 두더지들은 시간이 지나면 확률로 빨간색이 됩니다." << endl << endl;
    cout << "빨간색 두더지는 -5점" << endl << endl;
    cout << "시간제한은 오른쪽 아래에 속도가 60이 될때까지 입니다";
    gotoXY(12, 14);
    cout << "아무키나 누르세요";
}


void saveFile()
{
    ofstream writeToFile("score.txt");

    for (int i = 0; i < 5; i++)
    {
        string temp = to_string(highScore[i]);

        if (i < 4)
        {
            temp += "\n";
        }

        writeToFile.write(temp.c_str(), temp.size());
    }

    writeToFile.close();
}

void loadFile()
{
    ifstream readFromFile("score.txt");

    if (!readFromFile.is_open())
    {
        saveFile();

        readFromFile.open("score.txt");	// open안되서 다시 open
    }

    int i = 0;

    while (!readFromFile.eof())
    {
        string temp;
        getline(readFromFile, temp);

        highScore[i] = stoi(temp);

        i++;
    }

    readFromFile.close();
}

void saveScore(int score)	// currentScore를 바로 사용하지 않고 파라미터로 받는 것이 확장성 면에서 좋음
{
    for (int i = 0; i < 5; i++)
    {
        if (score >= highScore[i])
        {
            for (int j = 3; j >= i; j--)
            {
                highScore[j + 1] = highScore[j];
            }

            highScore[i] = score;
            break;
        }
    }
}

// 두더지 구멍이 겹치지 않게 정해주는 함수
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
    srand((unsigned)time(NULL));
    cursorVisible(false);
    SetConsoleView();

    loadFile();


    while (true)
    {

        // 메뉴 s 누르면 시작
        // 스코어 표기

        drawMenu();
        int inputKey = tolower(_getch());
        if (inputKey == 's')
        {
            DrawMap();
            initData();
            score = 0;

            while (true)
            {
                isRight = true;

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

                if (key != 0)
                {
                    isRight = false;
                }

                for (int i = 0; i < (int)moles.size(); i++)
                {
                    if (moles[i].compareKey(key))
                    {
                        if (moles[i].getIsFake())
                        {
                            score -= 5;
                            PlaySound(TEXT("not.wav"), NULL, SND_ASYNC);

                            moles[i].deleteMole();
                            moles.erase(moles.begin() + i);
                            i--;

                            isRight = true;
                            break;
                        }
                        else
                        {
                            score++;
                            PlaySound(TEXT("right.wav"), NULL, SND_ASYNC);

                            moles[i].deleteMole();
                            moles.erase(moles.begin() + i);
                            i--;

                            isRight = true;
                            break;
                        }
                    }
                }

                if (!isRight)
                {
                    score--;
                    PlaySound(TEXT("not.wav"), NULL, SND_ASYNC);
                }

                //두더지 일정시간후 사라짐
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

                //점점 빨라지고 일정 수준이 되면 게임 종료
                if (gameSpeed > 60)
                {
                    gameSpeed -= 0.1f;
                }
                else
                {
                    drawEnd();

                    saveScore(score);
                    saveFile();

                    break;
                }
            }
        }
        else if (inputKey == 'o')
        {
            drawManual();

            _getch();   //아무키나 누르세요
        }
        else if(inputKey == 'x')
        {
            exit(0);
        }
    }
}
