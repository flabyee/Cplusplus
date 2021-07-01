#include <iostream>
using namespace std;

int t(char ch) // '0'~'9'가 48~57이므로 48을 빼서 0~9로 바꾸는 함수
{
    return ch - 48;
}

int main()
{
    char identity[14];
    cin >> identity;
    if (t(identity[6]) % 2 == 1)
    {
        cout << "남자" << endl;
    }
    else
    {
        cout << "여자" << endl;
    }

    int year = t(identity[0]) * 10 + t(identity[1]);
    year += t(identity[6]) <= 2 ? 1900 : 2000;

    cout << "출생연도 : " << year << endl;
    cout << "나이 : " << 2021 - year + 1 << endl;

    int areaNumber = t(identity[7]) * 10 + t(identity[8]);

    if (areaNumber < 9)
    {
        cout << "서울" << endl;
    }
    else if (areaNumber < 13)
    {
        cout << "부산" << endl;
    }
    else  if (areaNumber < 16)
    {
        cout << "인천" << endl;
    }
    else   if (areaNumber < 19)
    {
        cout << "경기도 주요 도시" << endl;
    }
    else   if (areaNumber < 26)
    {
        cout << "그 밖의 경기도" << endl;
    }
    else  if (areaNumber < 35)
    {
        cout << "강원도" << endl;
    }
    else   if (areaNumber < 40)
    {
        cout << "충청북도" << endl;
    }
    else   if (areaNumber < 48)
    {
        cout << "충청남도" << endl;
    }
    else  if (areaNumber < 55)
    {
        cout << "전라북도" << endl;
    }
    else   if (areaNumber < 67)
    {
        cout << "전라남도" << endl;
    }
    else   if (areaNumber < 91)
    {
        cout << "경상도" << endl;
    }

    int total = 0;
    for (int i = 0; i < 8; i++)
    {

        total += t(identity[i]) * (i + 2);
    }
    for (int i = 0; i < 4; i++)
    {
        total += t(identity[i + 8]) * (i + 2);
    }

    int M = (11 - (total % 11)) % 10;

    if (M == (identity[12] - 48))
    {
        cout << "유효성 검사 성공" << endl;
    }
    else
    {
        cout << "유효성 검사 실패" << endl;
    }
}