#include <iostream>
using namespace std;

int gaus(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return num + gaus(num - 1);
}

int main()
{
    int num;
    cin >> num;
    cout << "1���� " << num << "������ ���� " << gaus(num) << endl;

    return 0;
}
