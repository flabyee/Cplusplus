#include <iostream>
#include <time.h>

int main()
{
	srand(time(NULL));
	int answer[3] = { 0, };

	answer[0] = rand() % 9 + 1;

	do
	{
		answer[1] = rand() % 9 + 1;
	} while (answer[0] == answer[1]);

	do
	{
		answer[2] = rand() % 9 + 1;
	} while (answer[0] == answer[2] || answer[1] == answer[2]);

	for (int i = 0; i < 3; i++)
	{
		std::cout << answer[i] << ' ';
	}

	int input[3] = { 0, };
	while (true)
	{
		std::cin >> input[0] >> input[1] >> input[2];

		for (int i = 0; i < 3; i++)
		{
			std::cout << answer[i] << ' ';
		}
		std::cout << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cout << input[i] << ' ';
		}
		std::cout << std::endl;

		int strike = 0, ball = 0, out = 0;

		for (int i = 0; i < 3; i++)
		{
			if (input[i] == answer[i])
			{
				strike++;
			}
			for (int j = 0; j < 3; j++)
			{

				if (input[i] == answer[j] && i != j)
				{
					ball++;
				}
			}
		}

		if (ball == 0 && strike == 0)
		{
			std::cout << "아웃" << std::endl;
		}
		else
		{
			if (strike == 3)
			{
				std::cout << "정답" << std::endl;
				return 0;
			}
			std::cout << "스트라이크 : " << strike << std::endl << "볼 : " << ball << std::endl;
		}
	}

	return 0;
}