#pragma once

#include <Windows.h>
#include <conio.h>

void textcolor(int foreground, int background = 0);
void gotoXY(int x, int y);
void cursorVisible(bool b);	// Ŀ�� ������ ����
int getKeyDown();
