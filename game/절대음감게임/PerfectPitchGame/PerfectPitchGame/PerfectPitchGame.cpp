#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

const int Tone[8] = { 523, 587, 659, 698, 784, 880, 988,1046 };
const string name[8] = { "도", "레", "미", "파", "솔", "라", "시", "도" };


int main()
{
	
	srand((unsigned)time(NULL));
	int selectTone = 0;
	int key = 0;

	cout << '0' << "을 입력하면 종료" << endl;
	while (true)
	{
		for (int i = 0; i < 8; i++)
		{
			cout << name[i] << '(' << i + 1 << ')' << ' ';
			Beep(Tone[i], 500);
		}
		Sleep(500);
		selectTone = rand() % 8;
		Beep(Tone[selectTone], 500);

		key = _getch() - '1';


		if (key == -1)
		{
			return 0;
		}
		else if (selectTone == key)
		{
			cout << "good " << "정답은 " << name[selectTone] << endl;
		}
		else
		{
			cout << "bad " << "정답은 " << name[selectTone] << endl;
		}
		Sleep(1000);
	}
	return 0;
}