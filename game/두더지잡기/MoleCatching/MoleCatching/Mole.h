#pragma once

class Mole
{
private:
    int moleNum;    //몇번째 두더지인지
    int holeNum;    //몇번째 구멍에 있는지
    bool isFake;    //파란색인가 빨간색인가 (true면 red)

    int life;

    char mole[3][4] =
    {
        "_#_",
        "| |",
        "| |"
    };

    char hole[3][4] =
    {
        "   ",
        "   ",
        "___"
    };

    static int num;

public:
    char key;   //어떤 키를 눌러야 하는가
    //두더지 값 초기화 및 그리기
    void initMole();
    //구멍 번호 얻기
    int getHoleNum();
    //입력 알파벳 얻기
    char getKey();
    //두더지 번호 얻기
    int getMoleNum();
    // 색깔 얻기
    bool getIsFake();
    //두더지 그리기
    void drawMole();
    //두더지 삭제
    void deleteMole();
    //두더지 이미 누구 있는지 확인하고 빈 곳에 지정
    void setHoleNum(int value);
    //시간후에 삭제 + 일정 확률로 fake로 변함
    bool isEnd();
    //누른 키와 두더지의 키 값이 같은지 비교
    bool compareKey(char _key);

};

