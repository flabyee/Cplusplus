#include <iostream>
using namespace std;

int Factorial(int num)
{
    if (num == 1)
    {
        return 1;
    }
    return num * Factorial(num - 1);
}

int main()
{
    int num;
    cin >> num;
    cout << "1���� " << num << "������ ���� " << Factorial(num) << endl;

    return 0;
}