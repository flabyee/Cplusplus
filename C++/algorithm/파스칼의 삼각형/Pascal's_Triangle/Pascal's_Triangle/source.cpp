#include <iostream>
using namespace std;

int main()
{
    int num[10][10] = { 0, };
    for (int i = 0; i < 10; i++)
    {
        num[i][0] = 1;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i > 0 && j > 0)
            {
                num[i][j] = num[i - 1][j] + num[i - 1][j - 1];
            }
            if (num[i][j] > 0)
            {
                cout << num[i][j] << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}