#include <iostream>
using namespace std;

void HanoiTower(int num, char from, char by, char to)
{
    if (num == 1)
    {
        cout << "원반 1을 " << from << "에서 " << to << "로 이동" << endl;
    }
    else
    { 
        HanoiTower(num - 1, from, to, by);

        cout << "원반 " << num << "을" << from << "에서 " << to << "로 이동" << endl;

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