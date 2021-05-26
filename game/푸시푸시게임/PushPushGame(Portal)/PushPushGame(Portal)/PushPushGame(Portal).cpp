#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define UP		72
#define DOWN	80
#define LEFT	75
#define RIGHT	77

char Stage[10][16] =
{
	"+++++++++++++++",
	"++++++      +++",
	"++  &  ++++ +++",
	"++  O  ++++@+++",
	"++ O O ++++.+++",
	"++     ++++.+++",
	"++++++    +.+++",
	"+++++ @  ++++++",
	"+++++    ++++++",
	"+++++++++++++++"
};
char backgroundMap[10][16];
int currentX, currentY;
int totalMove;

int portalPos[2][2];

void getPortalPos()
{
	int count = 0;
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (Stage[y][x] == '@' && count < 2)
			{
				portalPos[count][0] = y;
				portalPos[count][1] = x;
				count++;
			}
		}
	}
}
void gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

void clrscr()
{
	system("cls");
}

void initScreen()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			gotoXY(x, y);
			_putch(backgroundMap[y][x]);
		}
	}

	gotoXY(currentX, currentY);
	_putch('&');
	gotoXY(20, 5);
	cout << totalMove;

}

bool checkEnd()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (Stage[y][x] == '.' && backgroundMap[y][x] != 'O')
			{
				return false;
			}
		}
	}

	return true;
}

void move(int dir)
{
	int dir_x = 0, dir_y = 0;

	switch (dir)
	{
	case LEFT:
		dir_x = -1;
		break;
	case RIGHT:
		dir_x = 1;
		break;
	case UP:
		dir_y = -1;
		break;
	case DOWN:
		dir_y = 1;
		break;
	}

	if (backgroundMap[currentY + dir_y][currentX + dir_x] != '+')
	{
		if (backgroundMap[currentY + dir_y][currentX + dir_x] == 'O')
		{
			if (Stage[currentY + dir_y * 2][currentX + dir_x * 2] == '@')
			{
				if (currentY + dir_y * 2 == portalPos[0][0] && currentX + dir_x * 2 == portalPos[0][1])
				{
					backgroundMap[portalPos[1][0]][portalPos[1][1]] = 'O';
					backgroundMap[currentY + dir_y][currentX + dir_x] = ' ';
				}
				else
				{
					backgroundMap[portalPos[0][0]][portalPos[0][1]] = 'O';
					backgroundMap[currentY + dir_y][currentX + dir_x] = ' ';
				}
				backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] = '@';
			}
			else if (backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] == ' '
				|| backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] == '.')
			{
				if (Stage[currentY + dir_y][currentX + dir_x] == '@')
				{
					backgroundMap[currentY + dir_y][currentX + dir_x] = '@';
				}
				else if (Stage[currentY + dir_y][currentX + dir_x] == '.')
				{
					backgroundMap[currentY + dir_y][currentX + dir_x] = '.';
				}
				else
				{
					backgroundMap[currentY + dir_y][currentX + dir_x] = ' ';
				}
				backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] = 'O';
			}
			else
			{
				return;
			}
		}

		currentX += dir_x;
		currentY += dir_y;
		++totalMove;
	}
}

int main()
{
ReStart:
	int ch;


	memcpy(backgroundMap, Stage, sizeof(backgroundMap));
	getPortalPos();
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (Stage[y][x] == '&')
			{
				currentX = x;
				currentY = y;
				backgroundMap[y][x] = ' ';
			}
		}
	}

	clrscr();
	totalMove = 0;

	while (true)
	{
		initScreen();

		ch = _getch();

		//방향키
		if (ch == 0xE0 || ch == 0)
		{
			ch = _getch();

			switch (ch)
			{
			case LEFT:
			case RIGHT:
			case UP:
			case DOWN:
				move(ch);
				break;

			}
		}
		//일반키
		else
		{
			ch = tolower(ch);
			if (ch == 'q')
			{
				clrscr();
				exit(0);
			}
			if (ch == 'r')
			{
				goto ReStart;
			}
		}

		if (checkEnd())
		{
			clrscr();
			gotoXY(10, 4);
			printf("잘 풀었습니다 아무키나 입력하세요 총 움직인 횟수 : %d", totalMove);
			_getch();
			clrscr();
			exit(0);
			break;
		}
	}


	return 0;
}