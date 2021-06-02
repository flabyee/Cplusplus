#pragma once

class Mole
{
private:
    //int moleNum;    //���° �δ�������
    int holeNum;    //���° ���ۿ� �ִ���
    bool isRed;    //�Ķ����ΰ� �������ΰ� (true�� red)
    char key;   //� Ű�� ������ �ϴ°�

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
    //�δ��� �� �ʱ�ȭ �� �׸���
    void initMole();
    //���� ��ȣ ���
    int getHoleNum();
    //�δ��� �׸���
    void drawMole();
    //�δ��� ����
    void deleteMole();
    //�δ��� �̹� ���� �ִ��� Ȯ���ϱ�

    //�ð��Ŀ� ����
    void isEnd();

};

