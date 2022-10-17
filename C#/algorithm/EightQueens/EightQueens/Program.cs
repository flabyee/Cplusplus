using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace EightQueens
{
    // 0 : 비어있음
    // 1 : 퀸
    // 2 : 설치불가지역
    // 3 : 벽

    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(ReadLine());
            int queenCount = 0;

            int[,] board = new int[10, 10];

            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    if(i < n && j < n)
                        board[i, j] = 0;
                    else
                        board[i, j] = 3;
                }
            }

            while(true)
            {
               if (queenCount == n) break;

                bool exit = false;

                int y = 0;
                int x = 0;

               

                // 빈곳을 찾아서 _i, _j에 넣어줌
                for (int _y = 0; _y < n; _y++)
                {
                    for (int _x = 0; _x < n; _x++)
                    {
                        if (board[_y, _x] == 0)
                        {
                            y = _y;
                            x = _x;
                            exit = true;
                            break;
                        }
                    }
                    if (exit)
                        break;
                }

                // 찾은 빈곳에 퀸 배치
                board[y, x] = 1;
                queenCount++;

                // 배치 불가능지역 지정
                for (int _y = 0; _y < n; _y++)
                {
                    for (int _x = 0; _x < n; _x++)
                    {
                        // 가로줄 검사
                        if (board[y, _x] == 0)
                            board[y, _x] = 2;
                        // 세로줄 검사
                        if (board[_y, x] == 0)
                            board[_y, x] = 2;
                        // 대각선 검사
                        {
                            int tempY;
                            int tempX;
                        
                            // 왼쪽 윗 대각선
                            tempY = y;
                            tempX = x;
                            while (tempY >= 1 && tempX >= 1)
                            {
                                if (board[--tempY, --tempX] == 0)
                                {
                                    board[tempY, tempX] = 2;
                                }
                            } 

                            

                            // 오른쪽 윗 대각선
                            tempY = y;
                            tempX = x;
                            while (tempY >= 1 && tempX < n - 1)
                            {
                                if (board[--tempY, ++tempX] == 0)
                                {
                                    board[tempY, tempX] = 2;
                                }
                            } 

                            // 왼쪽 아랫 대각선
                            tempY = y;
                            tempX = x;
                            while (tempY < n - 1 && tempX >= 1)
                            {
                                if (board[++tempY, --tempX] == 0)
                                {
                                    board[tempY, tempX] = 2;
                                }
                            } 

                            // 오른쪽 아랫 대각선
                            tempY = y;
                            tempX = x;
                            while (tempY < n - 1 && tempX < n - 1)
                            {
                                if (board[++tempY, ++tempX] == 0)
                                {
                                    board[tempY, tempX] = 2;
                                }
                            } 
                        }
                    }
                }
            }


            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Write(board[i, j]);
                }
                WriteLine();
            }
        }

        
    }
}
