#include "Hanja.h"

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
