#include <iostream>
using namespace std;

#include <string>
string nums;

//ù��° ���

//string re(int num, int Digits)
//{
//    if (num == 0)
//    {
//        return nums;
//    }
//    else
//    {
//
//        return re((num - (num / Digits * Digits)) * 10, Digits) + to_string(num / Digits) + nums;
//
//    }
//}

//�ι�° ���
string re2(int num)
{
    if (num == 0)
    {
        return nums;
    }
    else
    {
        return nums + to_string(num % 10) + re2((num - (num % 10)) / 10);
    }
}

int main()
{
    int num;
    cin >> num;

    cout << re2(num); 

    return 0;
}