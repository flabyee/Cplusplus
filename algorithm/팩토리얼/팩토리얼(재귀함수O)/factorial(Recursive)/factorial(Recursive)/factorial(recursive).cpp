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
    cout << "1부터 " << num << "까지의 곱은 " << Factorial(num) << endl;

    return 0;
}