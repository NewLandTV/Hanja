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
	// 8ÐäùÓí® 
	{ "Îè", "±³" },
	{ "Îç", "±³" },
	{ "Îú", "±¸" },
	{ "ÏÐ", "±¹" },
	{ "ÏÚ", "±º" },
	{ "ÑÑ", "±Ý" },
	{ "Ñõ", "³²" },
	{ "Ò³", "³à" },
	{ "Ò´", "³â" },
	{ "ÓÞ", "´ë" },
	{ "ÔÔ", "µ¿" },
	{ "×¿", "·ú" },
	{ "Ø¿", "¸¸" },
	{ "Ù½", "¸ð" },
	{ "ÙÊ", "¸ñ" },
	{ "Ú¦", "¹®" },
	{ "ÚÅ", "¹Î" },
	{ "ÛÜ", "¹é" },
	{ "Ý«", "ºÎ" },
	{ "ÝÁ", "ºÏ" },
	{ "ÞÌ", "»ç" },
	{ "ß£", "»ê" },
	{ "ß²", "»ï" },
	{ "ßæ", "»ý" },
	{ "à¤", "¼­" },
	{ "à»", "¼±" },
	{ "á³", "¼Ò" },
	{ "â©", "¼ö" },
	{ "ãø", "½Ç" },
	{ "ä¨", "½Ê" },
	{ "çé", "¿À" },
	{ "èÝ", "¿Õ" },
	{ "èâ", "¿Ü" },
	{ "êÅ", "¿ù" },
	{ "ì£", "ÀÌ" },
	{ "ìÑ", "ÀÎ" },
	{ "ìé", "ÀÏ" },
	{ "ìí", "ÀÏ" },
	{ "íþ", "Àå" },
	{ "ð©", "Á¦" },
	{ "ñé", "Áß" },
	{ "ôì", "Ã»" },
	{ "õ»", "ÃÌ" },
	{ "öÒ", "Ä¥" },
	{ "÷Ï", "Åä" },
	{ "ø¢", "ÆÈ" },
	{ "ùÊ", "ÇÐ" },
	{ "ùÛ", "ÇÑ" },
	{ "úü", "Çü" },
	{ "ûý", "È­" },
	
	// 7ÐäIIùÓí® 
	{ "Ê«", "°¡" },
	{ "Êà", "°£" },
	{ "Ë°", "°­" },
	{ "ó³", "Â÷" },
	{ "Íï", "°ø" },
	{ "Íö", "°ø" },
	{ "Ñ¨", "±â" },
	{ "ÑÀ", "±â" },
	{ "Ñû", "³²" },
	{ "Ò®", "³»" },
	{ "ÒÜ", "³ó" },
	{ "ÓÍ", "´ä" },
	{ "Ô³", "µµ" },
	{ "ÔÑ", "µ¿" },
	{ "Õô", "·Â" },
	{ "Ø¡", "¸³" },
	{ "Øß", "¸Å" },
	{ "Ù£", "¸í" },
	{ "Úª", "¹°" },
	{ "Û°", "¹æ" },
	{ "Üô", "ºÒ" },
	{ "ÞÀ", "»ç" },
	{ "ß¾", "»ó" },
	{ "àó", "¼º" },
	{ "á¦", "¼¼" },
	{ "â¢", "¼ö" },
	{ "ãÁ", "½Ã" },
	{ "ã¼", "½Ã" },
	{ "ãÝ", "½Ä" },
	{ "äÌ", "¾È" },
	{ "çí", "¿À" },
	{ "éÓ", "¿À" },
	{ "í­", "ÀÚ" },
	{ "í»", "ÀÚ" },
	{ "íÞ", "Àå" },
	{ "ï³", "Àü" },
	{ "îñ", "Àü" },
	{ "îï", "Àü" },
	{ "ïá", "Á¤" },
	{ "ðë", "Á·" },
	{ "ñ§", "ÁÂ" },
	{ "òÁ", "Á÷" },
	{ "øÁ", "Æò" },
	{ "ù»", "ÇÏ" },
	{ "ùÓ", "ÇÑ" },
	{ "ú­", "ÇØ" },
	{ "ü¥", "È­" },
	{ "üÀ", "È°" },
	{ "üø", "È¿" },
	{ "ý­", "ÈÄ" },
	
	// 7ÐäùÓí® 
	{ "Ê°", "°¡" },
	{ "Ï¢", "±¸" },
	{ "Ðý", "±â" },
	{ "ÔÒ", "µ¿" },
	{ "Ô×", "µ¿" },
	{ "ÔÏ", "µ¿" },
	{ "Ôô", "µî" },
	{ "ÕÎ", "·¡" },
	{ "ÖÕ", "·Î" },
	{ "×ì", "¸®" },
	{ "×ù", "¸²" },
	{ "Øü", "¸é" },
	{ "Ù¤", "¸í" },
	{ "Ùþ", "¹®" },
	{ "Ùý", "¹®" },
	{ "ÛÝ", "¹é" },
	{ "Üý", "ºÎ" },
	{ "ß©", "»ê" },
	{ "ßä", "»ö" },
	{ "àª", "¼®" },
	{ "á´", "¼Ò" },
	{ "á¶", "¼Ò" },
	{ "â¦", "¼ö" },
	{ "ãÕ", "½Ä" },
	{ "ãý", "½É" },
	{ "åÞ", "¾î" },
	{ "æÔ", "¿¬" },
	{ "êó", "À¯" },
	{ "ëÀ", "À°" },
	{ "ëé", "À¾" },
	{ "ìý", "ÀÔ" },
	{ "í®", "ÀÚ" },
	{ "ðÓ", "Á¶" },
	{ "ñ¬", "ÁÖ" },
	{ "ñ«", "ÁÖ" },
	{ "ñì", "Áß" },
	{ "òµ", "Áö" },
	{ "ò¢", "Áö" },
	{ "ô¶", "Ãµ" },
	{ "ô¸", "Ãµ" },
	{ "ô¹", "Ãµ" },
	{ "õ®", "ÃÊ" },
	{ "õ½", "ÃÌ" },
	{ "õÕ", "Ãß" },
	{ "õð", "Ãá" },
	{ "õó", "Ãâ" },
	{ "øµ", "Æí" },
	{ "ù¾", "ÇÏ" },
	{ "ü£", "È­" },
	{ "ýÌ", "ÈÞ" },
	
	// 6ÐäIIùÓí® 
	{ "ÊÀ", "°¢" },
	{ "ÊÇ", "°¢" },
	{ "Í£", "°è" },
	{ "Íª", "°è" },
	{ "ÍÔ", "°í" },
	{ "Íë", "°ø" },
	{ "Íì", "°ø" },
	{ "Íí", "°ø" },
	{ "Íý", "°ú" },
	{ "Î¡", "°ú" },
	{ "ÎÃ", "±¤" },
	{ "Ï¹", "±¸" },
	{ "ÐÑ", "±Ý" },
	{ "Ðá", "±Þ" },
	{ "Ó­", "´Ü" },
	{ "ÓÑ", "´ç" },
	{ "ÓÛ", "´ë" },
	{ "Óß", "´ë" },
	{ "Óñ", "µµ" },
	{ "ÔÁ", "µ¶" },
	{ "ÔÛ", "µ¿" },
	{ "Ôõ", "µî" },
	{ "äÅ", "¶ô" },
	{ "××", "¸®" },
	{ "×â", "¸®" },
	{ "Ù¥", "¸í" },
	{ "Ú¤", "¹®" },
	{ "Úâ", "¹Ý" },
	{ "Úã", "¹Ý" },
	{ "Úì", "¹Ý" },
	{ "Û¡", "¹ß" },
	{ "Û¯", "¹æ" },
	{ "Ý»", "ºÎ" },
	{ "ÝÂ", "ºÎ" },
	{ "Þä", "»ç" },
	{ "ßö", "¼­" },
	{ "àÊ", "¼±" },
	{ "àä", "¼³" },
	{ "à÷", "¼º" },
	{ "àý", "¼º" },
	{ "á¼", "¼Ò" },
	{ "âú", "¼ú" },
	{ "ã·", "½Ã" },
	{ "ãó", "½Å" },
	{ "ãê", "½Å" },
	{ "ãá", "½Å" },
	{ "ãæ", "½Å" },
	{ "å°", "¾à" },
	{ "å·", "¾à" },
	{ "åö", "¾÷" },
	{ "é¸", "¿ë" },
	{ "éÄ", "¿ë" },
	{ "ê¡", "¿î" },
	{ "ëå", "À½" },
	{ "ëæ", "À½" },
	{ "ëò", "ÀÇ" },
	{ "íÂ", "ÀÛ" },
	{ "íÆ", "ÀÛ" },
	{ "î¦", "Àç" },
	{ "îú", "Àü" },
	{ "ïÔ", "Á¤" },
	{ "ð¯", "Á¦" },
	{ "ð¹", "Á¦" },
	{ "ñ¼", "ÁÖ" },
	{ "ó¢", "Áý" },
	{ "óë", "Ã¢" },
	{ "ôè", "Ã»" },
	{ "ô÷", "Ã¼" },
	{ "øú", "Ç¥" },
	{ "ù¦", "Ç³" },
	{ "ú¹", "Çà" },
	{ "úÞ", "Çö" },
	{ "û¡", "Çü" },
	{ "ûú", "È­" },
	{ "üå", "È¸" }
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
	system("title ùÓí®");
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
	fputs("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤", stdout);
	Gotoxy(23, 2);
	fputs("¦¢   ùÓí®   ¦¢", stdout);
	Gotoxy(23, 3);
	fputs("¦¢   ãËúÐ   ¦¢", stdout);
	Gotoxy(23, 4);
	fputs("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥", stdout);
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
	fputs("ó­ªÎùÓí®ªÎëåÔÁªòßöª¤ªÆª¯ªÀªµª¤¡£\n", stdout);
	fputs(hanja[index].data, stdout);
	fputc('\n', stdout);
	scanf("%s", input);
	
	// Check answer.
	if (strcmp(input, hanja[index].pronunciation) == 0)
	{
		score++;
		
		fputs("ïáÓÍ!\n", stdout);
		
		return;
	}
	
	fputs("è¦ÓÍ!\n", stdout);
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
	fputs("ó­ªÎùÓí®ªÎëåÔÁªËõÌªâÕÞª¤ªâªÎªò1 ª«ªé4ªÎñéª«ªéìéªÄàÔªóªÇª¯ªÀªµª¤¡£\n", stdout);
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
		
		fputs("ïáÓÍ!\n", stdout);
		
		return;
	}
	
	fputs("è¦ÓÍ!\n", stdout);
}
