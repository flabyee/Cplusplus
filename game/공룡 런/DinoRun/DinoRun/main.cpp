#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define DINO_TOP_Y      1
#define DINO_BOTTOM_Y   12
#define TREE_BOTTOM_X   45
#define TREE_BOTTOM_Y   20

#define BULLET_BOTTOM_X 7
#define BULLET_BOTTOM_Y 20

#define BIRD_BOTTOM_X   45
#define BIRD_BOTTOM_Y   5

#define BIRDBULLET_BOTTOM_X 7
#define BIRDBULLET_BOTTOM_Y 12


bool isJumping = false;
bool isBottom = true;
bool isGameover = false;
bool isShoot = false;
bool isShootStart = false;
bool isShootB = false;
bool isShootStartB = false;

int dinoY = DINO_BOTTOM_Y;
int treeX = TREE_BOTTOM_X;
int bulletX = -5;
int birdX = BIRD_BOTTOM_X;
int birdBulletY = 0;

int score = 0;

void gotoXY(int x, int y)
{
    HANDLE hOut;
    COORD Cur;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Cur.X = x * 2;
    Cur.Y = y;
    SetConsoleCursorPosition(hOut, Cur);
}

void clrscr()
{
    system("cls");
}

/*
"        $$$$$$$ "
"       $$ $$$$$$"
"       $$$$$$$$$"
"$      $$$      "
"$$     $$$$$$$  "
"$$$   $$$$$     "
" $$  $$$$$$$$$$ "
" $$$$$$$$$$$    "
"  $$$$$$$$$$    "
"    $$$$$$$$    "
"     $$$$$$     "
"     $    $$$   "
"     $$         "

"        $$$$$$$ "
"       $$ $$$$$$"
"       $$$$$$$$$"
"$      $$$      "
"$$     $$$$$$$  "
"$$$   $$$$$     "
" $$  $$$$$$$$$$ "
" $$$$$$$$$$$    "
"  $$$$$$$$$$    "
"    $$$$$$$$    "
"     $$$$$$     "
"     $$$  $     "
"          $$    "
*/

bool bLegFlag;

void setConsoleView()
{
    system("mode con:cols=100 lines=25");
    system("title ���� ����");
}


void drawDino(int posY)
{

    gotoXY(0, posY);
    cout << "        $$$$$$$ " << endl;
    cout << "       $$ $$$$$$" << endl;
    cout << "       $$$$$$$$$" << endl;
    cout << "$      $$$      " << endl;
    cout << "$$     $$$$$$$  " << endl;
    cout << "$$$   $$$$$     " << endl;
    cout << " $$  $$$$$$$$$$ " << endl;
    cout << " $$$$$$$$$$$    " << endl;
    cout << "  $$$$$$$$$$    " << endl;
    cout << "    $$$$$$$$    " << endl;
    cout << "     $$$$$$     " << endl;

    if (bLegFlag)
    {
        cout << "     $    $$$   " << endl;
        cout << "     $$         ";
    }
    else
    {
        cout << "     $$$  $     " << endl;
        cout << "          $$    ";
    }
    bLegFlag = !bLegFlag;
}

void drawTree(int posX)
{
    gotoXY(posX, TREE_BOTTOM_Y);
    cout << "$$$$";
    gotoXY(posX, TREE_BOTTOM_Y + 1);
    cout << "$$$$";
    gotoXY(posX, TREE_BOTTOM_Y + 2);
    cout << "$$$$";
    gotoXY(posX, TREE_BOTTOM_Y + 3);
    cout << " $$ ";
    gotoXY(posX, TREE_BOTTOM_Y + 4);
    cout << " $$ ";

}

void drawBullet(int posX)
{
    gotoXY(posX, BULLET_BOTTOM_Y);
    cout << "**";
    gotoXY(posX, BULLET_BOTTOM_Y + 1);
    cout << "**";
}

void drawBird(int posX)
{
    gotoXY(posX, BIRD_BOTTOM_Y);
    cout << "  *";
    gotoXY(posX, BIRD_BOTTOM_Y + 1);
    cout << " * ";
    gotoXY(posX, BIRD_BOTTOM_Y + 2);
    cout << "*  ";
    gotoXY(posX, BIRD_BOTTOM_Y + 3);
    cout << " * ";
    gotoXY(posX, BIRD_BOTTOM_Y + 4);
    cout << "  *";
}

void drawBirdBullet(int posY)
{
    gotoXY(BIRDBULLET_BOTTOM_X, posY);
    cout << "**";
    gotoXY(BIRDBULLET_BOTTOM_X, posY + 1);
    cout << "**";
}

void drawScore()
{
    gotoXY(45, 0);
    cout << "SCORE : " << score;
}

void drawGameOver()
{
    gotoXY(10, 10);
    cout << "GAME OVER";
}

void getKeyDown()
{
    int key;
    if (_kbhit() != 0)
    {
        key = _getch();
        if (key == 'j' && isBottom && !isGameover)
        {
            isJumping = true;
            isBottom = false;
        }
        else if (key == 'a' && !isShoot)
        {
            isShoot = true;
            isShootStart = true;
            bulletX = BULLET_BOTTOM_X;
        }
        else if (key == 'u' && !isShootB)
        {
            isShootB = true;
            isShootStartB = true;
            birdBulletY = BIRDBULLET_BOTTOM_Y;
        }

    }

    return;
}

int main(void)
{
    bLegFlag = false;


    const int gravity = 3;



    setConsoleView();

    while (true)
    {
        getKeyDown();

        if (treeX <= 6 && dinoY >= DINO_BOTTOM_Y - 4)
        {
            isGameover = true;
        }

        if (!isGameover)
        {
            if (isJumping)
            {
                dinoY -= gravity;
            }
            else
            {
                dinoY += gravity;
            }

            //���� ����
            if (dinoY <= DINO_TOP_Y)
            {
                dinoY = DINO_TOP_Y;
                isJumping = false;
            }
            else if (dinoY >= DINO_BOTTOM_Y)
            {
                dinoY = DINO_BOTTOM_Y;
                isBottom = true;
            }

            //���� �̵�
            treeX -= 2;
            if (treeX <= 0) treeX = TREE_BOTTOM_X;

            //�� �̵�
            birdX -= 1;
            if (birdX <= 0) birdX = BIRD_BOTTOM_X;

            //�Ѿ� �̵�
            if (isShoot)
            {
                if (isShootStart)
                {
                    bulletX = BULLET_BOTTOM_X;
                    isShootStart = false;
                }
                drawBullet(bulletX);
                bulletX += 2;
                if (bulletX >= 50)
                {
                    isShoot = false;
                    isShootStart = false;
                }
            }

            //�Ѿ�(��) �̵�
            if (isShootB)
            {
                if (isShootStartB)
                {
                    birdBulletY = BIRDBULLET_BOTTOM_Y;
                    isShootStartB = false;
                }
                drawBirdBullet(birdBulletY);
                birdBulletY -= 1;
                if (birdBulletY <= 0)
                {
                    isShootB = false;
                    isShootStartB = false;
                }
            }
        }
        else
        {
            drawGameOver();
        }

        drawDino(dinoY);
        drawTree(treeX);
        drawBird(birdX);



        if (bulletX - 2 <= treeX && bulletX + 2 >= treeX)
        {
            isShoot = false;
            isShootStart = false;
            bulletX = -5;
            treeX = TREE_BOTTOM_X;
            score++;
        }

        if (birdBulletY >= 5 && birdBulletY <= 9 && (birdX == 7 || birdX == 8)) //�Ѿ�y 5 6 7 8 9�϶� ��x 7 8 �̶��
        {
            isShootB = false;
            isShootStartB = false;
            birdBulletY = 0;
            birdX = BIRD_BOTTOM_X;
            score++;
        }




        drawScore();

        Sleep(80);
        clrscr();
    }
}