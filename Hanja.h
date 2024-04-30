#ifndef __HANJA_H__
#define __HANJA_H__

#include <Windows.h>

// Hanja datas and type of problem.
#define HANJA_COUNT 400
#define PROBLEM_TYPE_COUNT 2

// Macro functions
#define Gotoxy(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){ x, y })

// Structures
typedef struct _Hanja
{
	char data[3];
	char pronunciation[11];
} Hanja;

// Functions
void Init();
void DrawTitle();
void DrawScore();

// Problems
void Problem1();
void Problem2();

// Hanja data functions
int CheckAnswer(char* answer, char* input);
int GetPronunciation(int index, int pronunciationIndex, char* out);

#endif
