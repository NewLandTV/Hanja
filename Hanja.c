#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

// Hanja datas and type of problem.
#define HANJA_COUNT 150
#define PROBLEM_TYPE_COUNT 2

// Macro functions
#define Gotoxy(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD){ x, y })

// Structures
typedef struct _Hanja
{
	char data[3];
	char pronunciation[3];
} Hanja;

// Data
Hanja hanja[HANJA_COUNT] =
{
	// 8����� 
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "ҳ", "��" },
	{ "Ҵ", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "׿", "��" },
	{ "ؿ", "��" },
	{ "ٽ", "��" },
	{ "��", "��" },
	{ "ڦ", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "ݫ", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "ߣ", "��" },
	{ "߲", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "�", "��" },
	{ "�", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "��", "û" },
	{ "��", "��" },
	{ "��", "ĥ" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "ȭ" },
	
	// 7��II��� 
	{ "ʫ", "��" },
	{ "��", "��" },
	{ "˰", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "Ѩ", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "Ү", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "Գ", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "ء", "��" },
	{ "��", "��" },
	{ "٣", "��" },
	{ "ڪ", "��" },
	{ "۰", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "߾", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "ȭ" },
	{ "��", "Ȱ" },
	{ "��", "ȿ" },
	{ "��", "��" },
	
	// 7����� 
	{ "ʰ", "��" },
	{ "Ϣ", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "٤", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "ߩ", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "�", "��" },
	{ "�", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "�", "��" },
	{ "��", "õ" },
	{ "��", "õ" },
	{ "��", "õ" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "ȭ" },
	{ "��", "��" },
	
	// 6��II��� 
	{ "��", "��" },
	{ "��", "��" },
	{ "ͣ", "��" },
	{ "ͪ", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "Ρ", "��" },
	{ "��", "��" },
	{ "Ϲ", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "ӭ", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "٥", "��" },
	{ "ڤ", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "ۡ", "��" },
	{ "ۯ", "��" },
	{ "ݻ", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "�", "��" },
	{ "�", "��" },
	{ "�", "��" },
	{ "�", "��" },
	{ "��", "â" },
	{ "��", "û" },
	{ "��", "ü" },
	{ "��", "ǥ" },
	{ "��", "ǳ" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "ȭ" },
	{ "��", "ȸ" }
};

// To display the number of problems you have answered.
unsigned long long score;

// Functions
void Init();
void DrawTitle();
void DrawScore();
void Problem1();
void Problem2();

int main(void)
{
	int i;
	
	Init();
	DrawTitle();
	
	while (getchar() != 27)
	{
		system("cls");
		DrawScore();
		
		i = rand() % PROBLEM_TYPE_COUNT;
		
		switch (i)
		{
		case 0:
			Problem1();
			
			break;
		case 1:
			Problem2();
			
			break;
		}
		
		Sleep(1000);
	}
	
	return 0;
}

void Init()
{
	srand((unsigned int)time(0));
	
	// Setup console
	system("title ���");
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
	fputs("������������������������", stdout);
	Gotoxy(23, 2);
	fputs("��   ���   ��", stdout);
	Gotoxy(23, 3);
	fputs("��   ����   ��", stdout);
	Gotoxy(23, 4);
	fputs("������������������������", stdout);
	Gotoxy(16, 10);
	fputs("- PRESS ANY KEY TO START -", stdout);
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
	int index = rand() % HANJA_COUNT;
	char input[3];
	
	// Show and Input
	fputs("�����������������ƪ���������\n", stdout);
	fputs(hanja[index].data, stdout);
	fputc('\n', stdout);
	scanf("%s", input);
	
	// Check answer.
	if (strcmp(input, hanja[index].pronunciation) == 0)
	{
		score++;
		
		fputs("����!\n", stdout);
		
		return;
	}
	
	fputs("���!\n", stdout);
}

void Problem2()
{
	int i, j;
	int index = -1;
	int input;
	
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
			if (strcmp(list[i].pronunciation, list[j].pronunciation) == 0)
			{
				j--;
				list[j] = hanja[rand() % HANJA_COUNT - 1];
				
				continue;
			}
		}
	}
	
	// Show and Input
	fputs("�������������̪��ު���Ϊ�1 ����4���骫������Ԫ�Ǫ���������\n", stdout);
	fputs(hanja[index].data, stdout);
	fputc('\n', stdout);
	
	for (i = 0; i < 4; i++)
	{
		fprintf(stdout, "%d. %s\n", i + 1, list[i].pronunciation);
	}
	
	scanf("%d", &input);
	
	// Check answer.
	if (strcmp(list[input - 1].pronunciation, hanja[index].pronunciation) == 0)
	{
		score++;
		
		fputs("����!\n", stdout);
		
		return;
	}
	
	fputs("���!\n", stdout);
}
