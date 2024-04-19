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
	char pronunciation[11];
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
	{ "��", "��, ��" },
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
	{ "��", "��, ��" },
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
	{ "�", "��, ��" },
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
	{ "��", "��, ��" },
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
	{ "��", "��, ��" },
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
	{ "��", "��, ��" },
	{ "��", "��" },
	{ "��", "��" },
	{ "��", "��, ��, ��" },
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
	{ "��", "��, ��" },
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

// Problems
void Problem1();
void Problem2();

// Hanja data functions
int CheckAnswer(char* answer, char* input);
int GetPronunciation(int index, int pronunciationIndex, char* out);

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
	Gotoxy(1, 28);
	fputs("v0.4.0", stdout);
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
	char output[3];
	
	fputs("�����������������ƪ���������\n", stdout);
	fputs(hanja[index].data, stdout);
	fputc('\n', stdout);
	scanf("%s", input);
	
	// Check answer
	pr = GetPronunciation(index, 0, output);
	i = 0;
	
	if (pr == 2)
	{
		if (CheckAnswer(output, input))
		{
			return;
		}
		
		fputs("���!\n", stdout);
		
		return;
	}
	
	while (1)
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
		
		i++;
	}
	
	fputs("���!\n", stdout);
}

void Problem2()
{
	int i, j;
	int pr;
	int index = -1;
	int input;
	char output[3];
	
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
	
	// Check answer
	pr = GetPronunciation(index, 0, output);
	i = 0;
	
	if (pr == 2)
	{
		if (CheckAnswer(output, list[input - 1].pronunciation))
		{
			return;
		}
		
		fputs("���!\n", stdout);
		
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
	
	fputs("���!\n", stdout);
}

// Hanja data functions
int CheckAnswer(char* answer, char* input)
{
	if (strcmp(answer, input) != 0)
	{
		return 0;
	}
	
	score++;
	
	fputs("����!\n", stdout);
	
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
	}
	
	if (strcmp(out, temp) == 0)
	{
		return 0;
	}
	
	strcpy(out, temp);
	
	return 1;
}
