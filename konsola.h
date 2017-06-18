
#ifndef Konsola
#define Konsola
//=============================
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <locale>
//-----------------------------
void polskie_litery();
void gotoxy(int x, int y);
int wherex();
int wherey();
void clreol();
void HideCursor();
void ShowCursor();
void ustaw_kolor(int kolor);
//=============================
#endif
