#include <iostream>
using namespace std;

void mySort(int* nums, int count)
{
    int temp = 0;
    if (count == 0)
    {
        return;
    }
    else
    {
        for (int i = 0; i < count - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
            }
        }
        return mySort(nums, count - 1);
    }
}

int main()
{
    int nums[100] = { 0, };

    cout << "입력할 수의 갯수를 입력하세요" << endl;
    int c;
    cin >> c;

    cout << "수를 갯수번만큼 입력하세요" << endl;
    for (int i = 0; i < c; i++)
    {
        cin >> nums[i];
    }

    mySort(nums, sizeof(nums) / sizeof(int));

    cout << nums[0] << endl;

    return 0;
}