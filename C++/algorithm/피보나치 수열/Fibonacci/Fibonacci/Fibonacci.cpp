#include <iostream>
using namespace std;

int Fibonacci(int num)
{
    if (num == 1 || num == 2)
    {
        return 1;
    }
    else
    {
        return Fibonacci(num - 1) + Fibonacci(num - 2);
    }
}

int main()
{
    int num;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        cout << Fibonacci(i) << endl;
    }

    return 0;
}