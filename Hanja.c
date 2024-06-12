#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "Hanja.h"
#include "Data.h"

// To display the number of problems you have answered.
unsigned long long score;

void Init()
{
	srand((unsigned int)time(0));
	
	// Setup console
	system("title 漢字");
	system("mode con cols=60 lines=30");
	
	// Hide console cursor
	CONSOLE_CURSOR_INFO consoleCursorInfo;
	
	consoleCursorInfo.bVisible = 0;
	consoleCursorInfo.dwSize = 1;
	
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);
}

void DrawTitle()
{
	Gotoxy(23, 1);
	fputs("┌──────────┐", stdout);
	Gotoxy(23, 2);
	fputs("│   漢字   │", stdout);
	Gotoxy(23, 3);
	fputs("│   試驗   │", stdout);
	Gotoxy(23, 4);
	fputs("└──────────┘", stdout);
	Gotoxy(16, 10);
	fputs("- PRESS ANY KEY TO START -", stdout);
	Gotoxy(1, 28);
	fputs("v0.8.1", stdout);
	Gotoxy(0, 0);
}

void DrawScore()
{
	Gotoxy(32, 1);
	fprintf(stdout, "SCORE : %llu", score);
	Gotoxy(0, 2);
}

// Problems
void Problem1()
{
	int i;
	int pr;
	int index = rand() % HANJA_COUNT;
	char input[3];
	char output[15];
	
	fputs("次の漢字の音讀を書いてください。\n", stdout);
	fputs(hanja[index].data, stdout);
	fputc('\n', stdout);
	scanf("%s", input);
	
	// Check answer
	pr = GetPronunciation(index, 0, output);
	
	if (pr == 2)
	{
		if (CheckAnswer(output, input))
		{
			return;
		}
		
		fputs("誤答!\n", stdout);
		
		return;
	}
	
	for (i = 0; ; i++)
	{
		pr = GetPronunciation(index, i, output);
		
		if (pr == 0)
		{
			break;
		}
		
		if (CheckAnswer(output, input))
		{
			return;
		}
	}
	
	fputs("誤答!\n", stdout);
}

void Problem2()
{
	int i, j;
	int pr;
	int index = -1;
	int input;
	char output[15];
	
	Hanja list[4];
	
	// Choice 4 hanjas to display on the screen.
	for (i = 0; i < 4; i++)
	{
		if (rand() & 1 && index == -1)
		{
			index = rand() % HANJA_COUNT - 1;
			list[i] = hanja[index];
		}
		else
		{
			list[i] = hanja[rand() % HANJA_COUNT - 1];
		}
		
		for (j = 0; j < i; j++)
		{
			if (strcmp(list[i].data, list[j].data) == 0)
			{
				j--;
				list[j] = hanja[rand() % HANJA_COUNT - 1];
				
				continue;
			}
		}
	}
	
	// Show and Input
	fputs("次の漢字の音讀に最も良いものを1 から4の中から一つ選んでください。\n", stdout);
	fputs(hanja[index].data, stdout);
	fputc('\n', stdout);
	
	for (i = 0; i < 4; i++)
	{
		fprintf(stdout, "%d. %s\n", i + 1, list[i].pronunciation);
	}
	
	scanf("%d", &input);
	
	// Check answer
	pr = GetPronunciation(index, 0, output);
	i = 0;
	
	if (pr == 2)
	{
		if (CheckAnswer(output, list[input - 1].pronunciation))
		{
			return;
		}
		
		fputs("誤答!\n", stdout);
		
		return;
	}
	
	while (1)
	{
		pr = GetPronunciation(index, i, output);
		
		if (pr == 0)
		{
			break;
		}
		
		if (CheckAnswer(output, list[input - 1].pronunciation))
		{
			return;
		}
		
		i++;
	}
	
	fputs("誤答!\n", stdout);
}

// Hanja data functions
int CheckAnswer(char* answer, char* input)
{
	if (strcmp(answer, input) != 0)
	{
		return 0;
	}
	
	score++;
	
	fputs("正答!\n", stdout);
	
	return 1;
}

int GetPronunciation(int index, int pronunciationIndex, char* out)
{
	Hanja ptr = hanja[index];
	
	int i;
	char* temp;
	
	// Only one pronunciation.
	if (strlen(ptr.pronunciation) <= 3)
	{
		strcpy(out, ptr.pronunciation);
		
		return 2;
	}
	
	temp = strtok(ptr.pronunciation, ", ");
	
	for (i = 0; i < pronunciationIndex; i++)
	{
		temp = strtok(NULL, ", ");
		
		if (temp == NULL)
		{
			return 0;
		}
	}
	
	strcpy(out, temp);
	
	return 1;
}
