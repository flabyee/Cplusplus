#include <iostream>
using namespace std;

int t(char ch) // '0'~'9'�� 48~57�̹Ƿ� 48�� ���� 0~9�� �ٲٴ� �Լ�
{
    return ch - 48;
}

int main()
{
    char identity[14];
    cin >> identity;
    if (t(identity[6]) % 2 == 1)
    {
        cout << "����" << endl;
    }
    else
    {
        cout << "����" << endl;
    }

    int year = t(identity[0]) * 10 + t(identity[1]);
    year += t(identity[6]) <= 2 ? 1900 : 2000;

    cout << "������� : " << year << endl;
    cout << "���� : " << 2021 - year + 1 << endl;

    int areaNumber = t(identity[7]) * 10 + t(identity[8]);

    if (areaNumber < 9)
    {
        cout << "����" << endl;
    }
    else if (areaNumber < 13)
    {
        cout << "�λ�" << endl;
    }
    else  if (areaNumber < 16)
    {
        cout << "��õ" << endl;
    }
    else   if (areaNumber < 19)
    {
        cout << "��⵵ �ֿ� ����" << endl;
    }
    else   if (areaNumber < 26)
    {
        cout << "�� ���� ��⵵" << endl;
    }
    else  if (areaNumber < 35)
    {
        cout << "������" << endl;
    }
    else   if (areaNumber < 40)
    {
        cout << "��û�ϵ�" << endl;
    }
    else   if (areaNumber < 48)
    {
        cout << "��û����" << endl;
    }
    else  if (areaNumber < 55)
    {
        cout << "����ϵ�" << endl;
    }
    else   if (areaNumber < 67)
    {
        cout << "���󳲵�" << endl;
    }
    else   if (areaNumber < 91)
    {
        cout << "���" << endl;
    }

    int total = 0;
    for (int i = 0; i < 8; i++)
    {

        total += t(identity[i]) * (i + 2);
    }
    for (int i = 0; i < 4; i++)
    {
        total += t(identity[i + 8]) * (i + 2);
    }

    int M = (11 - (total % 11)) % 10;

    if (M == (identity[12] - 48))
    {
        cout << "��ȿ�� �˻� ����" << endl;
    }
    else
    {
        cout << "��ȿ�� �˻� ����" << endl;
    }
}