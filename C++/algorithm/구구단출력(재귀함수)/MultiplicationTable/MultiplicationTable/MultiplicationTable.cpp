#include <iostream>
using namespace std;

void ninenine(int dan)
{
    if (dan == 1)
    {
        return;
    }
    else
    {
        for (int i = 1; i < 10; i++)
        {
            cout << dan << '*' << i << '=' << dan * i << ' ';
        }
        cout << endl;
        return ninenine(dan - 1);
    }
}

int main()
{
    ninenine(9);

    return 0;
}