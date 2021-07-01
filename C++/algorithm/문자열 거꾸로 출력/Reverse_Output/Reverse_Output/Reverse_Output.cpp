#include <iostream>
using namespace std;

int main()
{
    char ch[3][30] = { 0, };

    for (int i = 0; i < 3; i++)
    {
        cin.getline(ch[i], 30);
    }

    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 29; j > -1; j--)
        {
            if (ch[i][j] > 0)
            {
                cout << ch[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}