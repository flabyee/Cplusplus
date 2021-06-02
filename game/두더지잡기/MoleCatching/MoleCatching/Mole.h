#pragma once

class Mole
{
private:
    //int moleNum;    //몇번째 두더지인지
    int holeNum;    //몇번째 구멍에 있는지
    bool isRed;    //파란색인가 빨간색인가 (true면 red)
    char key;   //어떤 키를 눌러야 하는가

    int life;
    bool isAlive;

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

public:
    //두더지 값 초기화 및 그리기
    void initMole();
    //구멍 번호 얻기
    int getHoleNum();
    //두더지 그리기
    void drawMole();
    //두더지 삭제
    void deleteMole();
    //두더지 이미 누구 있는지 확인하기

    //시간후에 삭제
    void isEnd();

};

