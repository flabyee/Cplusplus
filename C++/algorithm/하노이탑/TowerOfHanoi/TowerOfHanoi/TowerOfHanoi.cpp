#include <iostream>
using namespace std;

void HanoiTower(int num, char from, char by, char to)
{
    if (num == 1)
    {
        cout << "���� 1�� " << from << "���� " << to << "�� �̵�" << endl;
    }
    else
    { 
        HanoiTower(num - 1, from, to, by);

        cout << "���� " << num << "��" << from << "���� " << to << "�� �̵�" << endl;

        HanoiTower(num - 1, by, from, to);
    }
}
int main()
{
    int num;
    cin >> num;
    HanoiTower(num, 'A', 'B', 'C');

    return 0;
}