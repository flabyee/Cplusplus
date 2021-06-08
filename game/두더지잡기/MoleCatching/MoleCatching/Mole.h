#pragma once

class Mole
{
private:
    int moleNum;    //���° �δ�������
    int holeNum;    //���° ���ۿ� �ִ���
    bool isFake;    //�Ķ����ΰ� �������ΰ� (true�� red)

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
    char key;   //� Ű�� ������ �ϴ°�
    //�δ��� �� �ʱ�ȭ �� �׸���
    void initMole();
    //���� ��ȣ ���
    int getHoleNum();
    //�Է� ���ĺ� ���
    char getKey();
    //�δ��� ��ȣ ���
    int getMoleNum();
    // ���� ���
    bool getIsFake();
    //�δ��� �׸���
    void drawMole();
    //�δ��� ����
    void deleteMole();
    //�δ��� �̹� ���� �ִ��� Ȯ���ϰ� �� ���� ����
    void setHoleNum(int value);
    //�ð��Ŀ� ���� + ���� Ȯ���� fake�� ����
    bool isEnd();
    //���� Ű�� �δ����� Ű ���� ������ ��
    bool compareKey(char _key);

};

