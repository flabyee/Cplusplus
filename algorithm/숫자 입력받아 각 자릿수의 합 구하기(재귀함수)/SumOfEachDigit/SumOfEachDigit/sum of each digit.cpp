#include <iostream>
using namespace std;

int total = 0;

int re2(int num)
{
    if (num == 0)
    {
        return total;
    }
    else
    {
        total += num % 10;
        return re2((num - (num % 10)) / 10);
    }
}

int main()
{
    int num;
    cin >> num;

    cout << re2(num);

    return 0;
}