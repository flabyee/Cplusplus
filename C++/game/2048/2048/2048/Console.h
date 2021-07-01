#pragma once

#include <Windows.h>
#include <conio.h>

extern void setTextColor(int foreground, int background = 0);
extern void gotoXY(int x, int y);
extern void clrscr();
extern int getKeyDown();
extern void setNoCursor();
