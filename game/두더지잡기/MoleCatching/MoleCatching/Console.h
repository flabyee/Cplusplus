#pragma once

#include <Windows.h>
#include <conio.h>

void textcolor(int foreground, int background);
void gotoXY(int x, int y);
void cursorVisible(bool b);
int getKeyDown();
