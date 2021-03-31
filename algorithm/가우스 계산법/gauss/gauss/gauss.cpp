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
    cout << "1부터 " << num << "까지의 합은 " << gaus(num) << endl;

    return 0;
}
