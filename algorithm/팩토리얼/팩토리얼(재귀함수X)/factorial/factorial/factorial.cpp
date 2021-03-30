#include <iostream>
using namespace std;

int main()
{
    int num;
    int sum = 1;

    cin >> num;

    if (num == 0)
    {
        sum *= 0;
    }

    for (int i = 1; i <= num; i++)
    {
        sum *= i;
    }

    cout << sum << endl;

    return 0;
}