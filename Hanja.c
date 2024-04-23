#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

// Hanja datas and type of problem.
#define HANJA_COUNT 300
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
	// 8級漢字 
	{ "校", "교" },
	{ "敎", "교" },
	{ "九", "구" },
	{ "國", "국" },
	{ "軍", "군" },
	{ "金", "금, 김" },
	{ "南", "남" },
	{ "女", "녀" },
	{ "年", "년" },
	{ "大", "대" },
	{ "東", "동" },
	{ "六", "륙" },
	{ "萬", "만" },
	{ "母", "모" },
	{ "木", "목" },
	{ "門", "문" },
	{ "民", "민" },
	{ "白", "백" },
	{ "父", "부" },
	{ "北", "북, 배" },
	{ "四", "사" },
	{ "山", "산" },
	{ "三", "삼" },
	{ "生", "생" },
	{ "西", "서" },
	{ "先", "선" },
	{ "小", "소" },
	{ "水", "수" },
	{ "室", "실" },
	{ "十", "십" },
	{ "五", "오" },
	{ "王", "왕" },
	{ "外", "외" },
	{ "月", "월" },
	{ "二", "이" },
	{ "人", "인" },
	{ "一", "일" },
	{ "日", "일" },
	{ "長", "장" },
	{ "弟", "제" },
	{ "中", "중" },
	{ "靑", "청" },
	{ "寸", "촌" },
	{ "七", "칠" },
	{ "土", "토" },
	{ "八", "팔" },
	{ "學", "학" },
	{ "韓", "한" },
	{ "兄", "형" },
	{ "火", "화" },
	
	// 7級II漢字 
	{ "家", "가" },
	{ "間", "간" },
	{ "江", "강" },
	{ "車", "거, 차" },
	{ "工", "공" },
	{ "空", "공" },
	{ "氣", "기" },
	{ "記", "기" },
	{ "男", "남" },
	{ "內", "내" },
	{ "農", "농" },
	{ "答", "답" },
	{ "道", "도" },
	{ "動", "동" },
	{ "力", "력" },
	{ "立", "립" },
	{ "每", "매" },
	{ "名", "명" },
	{ "物", "물" },
	{ "方", "방" },
	{ "不", "불" },
	{ "事", "사" },
	{ "上", "상" },
	{ "姓", "성" },
	{ "世", "세" },
	{ "手", "수" },
	{ "時", "시" },
	{ "市", "시" },
	{ "食", "식" },
	{ "安", "안" },
	{ "午", "오" },
	{ "右", "오" },
	{ "子", "자" },
	{ "自", "자" },
	{ "場", "장" },
	{ "電", "전" },
	{ "前", "전" },
	{ "全", "전" },
	{ "正", "정" },
	{ "足", "족" },
	{ "左", "좌" },
	{ "直", "직" },
	{ "平", "평" },
	{ "下", "하" },
	{ "漢", "한" },
	{ "海", "해" },
	{ "話", "화" },
	{ "活", "활" },
	{ "孝", "효" },
	{ "後", "후" },
	
	// 7級漢字 
	{ "歌", "가" },
	{ "口", "구" },
	{ "旗", "기" },
	{ "同", "동" },
	{ "洞", "동, 통" },
	{ "冬", "동" },
	{ "登", "등" },
	{ "來", "래" },
	{ "老", "로" },
	{ "里", "리" },
	{ "林", "림" },
	{ "面", "면" },
	{ "命", "명" },
	{ "文", "문" },
	{ "問", "문" },
	{ "百", "백" },
	{ "夫", "부" },
	{ "算", "산" },
	{ "色", "색" },
	{ "夕", "석" },
	{ "少", "소" },
	{ "所", "소" },
	{ "數", "수" },
	{ "植", "식" },
	{ "心", "심" },
	{ "語", "어" },
	{ "然", "연" },
	{ "有", "유" },
	{ "育", "육" },
	{ "邑", "읍" },
	{ "入", "입" },
	{ "字", "자" },
	{ "祖", "조" },
	{ "住", "주" },
	{ "主", "주" },
	{ "重", "중" },
	{ "紙", "지" },
	{ "地", "지" },
	{ "千", "천" },
	{ "天", "천" },
	{ "川", "천" },
	{ "草", "초" },
	{ "村", "촌" },
	{ "秋", "추" },
	{ "春", "춘" },
	{ "出", "출" },
	{ "便", "편, 변" },
	{ "夏", "하" },
	{ "花", "화" },
	{ "休", "휴" },
	
	// 6級II漢字 
	{ "各", "각" },
	{ "角", "각" },
	{ "界", "계" },
	{ "計", "계" },
	{ "高", "고" },
	{ "公", "공" },
	{ "共", "공" },
	{ "功", "공" },
	{ "果", "과" },
	{ "科", "과" },
	{ "光", "광" },
	{ "球", "구" },
	{ "今", "금" },
	{ "急", "급" },
	{ "短", "단" },
	{ "堂", "당" },
	{ "代", "대" },
	{ "對", "대" },
	{ "圖", "도" },
	{ "讀", "독, 두" },
	{ "童", "동" },
	{ "等", "등" },
	{ "樂", "락, 악, 요" },
	{ "利", "리" },
	{ "理", "리" },
	{ "明", "명" },
	{ "聞", "문" },
	{ "半", "반" },
	{ "反", "반" },
	{ "班", "반" },
	{ "發", "발" },
	{ "放", "방" },
	{ "部", "부" },
	{ "分", "부" },
	{ "社", "사" },
	{ "書", "서" },
	{ "線", "선" },
	{ "雪", "설" },
	{ "成", "성" },
	{ "省", "성, 생" },
	{ "消", "소" },
	{ "術", "술" },
	{ "始", "시" },
	{ "身", "신" },
	{ "神", "신" },
	{ "信", "신" },
	{ "新", "신" },
	{ "弱", "약" },
	{ "藥", "약" },
	{ "業", "업" },
	{ "勇", "용" },
	{ "用", "용" },
	{ "運", "운" },
	{ "音", "음" },
	{ "飮", "음" },
	{ "意", "의" },
	{ "作", "작" },
	{ "昨", "작" },
	{ "才", "재" },
	{ "戰", "전" },
	{ "庭", "정" },
	{ "第", "제" },
	{ "題", "제" },
	{ "注", "주" },
	{ "集", "집" },
	{ "窓", "창" },
	{ "淸", "청" },
	{ "體", "체" },
	{ "表", "표" },
	{ "風", "풍" },
	{ "幸", "행" },
	{ "現", "현" },
	{ "形", "형" },
	{ "和", "화" },
	{ "會", "회" },
	
	// 6級漢字 
	{ "感", "감" },
	{ "強", "강" },
	{ "開", "개" },
	{ "京", "경" },
	{ "古", "고" },
	{ "苦", "고" },
	{ "交", "교" },
	{ "區", "구" },
	{ "郡", "군" },
	{ "根", "근" },
	{ "近", "근" },
	{ "級", "급" },
	{ "多", "다" },
	{ "待", "대" },
	{ "度", "도, 탁" },
	{ "頭", "두" },
	{ "例", "례" },
	{ "禮", "례" },
	{ "路", "로" },
	{ "綠", "록" },
	{ "李", "리" },
	{ "目", "목" },
	{ "美", "미" },
	{ "米", "미" },
	{ "朴", "박" },
	{ "番", "번" },
	{ "別", "별" },
	{ "病 ", "병" },
	{ "服", "복" },
	{ "本", "본" },
	{ "使", "사" },
	{ "死", "사" },
	{ "席", "석" },
	{ "石", "석" },
	{ "速", "속" },
	{ "孫", "손" },
	{ "樹", "수" },
	{ "習", "습" },
	{ "勝", "승" },
	{ "式", "식" },
	{ "失", "실" },
	{ "愛", "애" },
	{ "夜", "야" },
	{ "野", "야" },
	{ "陽 ", "양" },
	{ "洋", "양" },
	{ "言", "언" },
	{ "英", "영" },
	{ "永", "영" },
	{ "溫", "온" },
	{ "園", "원" },
	{ "遠", "원" },
	{ "由", "유" },
	{ "油", "유" },
	{ "銀", "은" },
	{ "醫", "의" },
	{ "衣", "의" },
	{ "者", "자" },
	{ "章", "장" },
	{ "在", "재" },
	{ "定", "정" },
	{ "朝", "조" },
	{ "族", "족" },
	{ "晝", "주" },
	{ "親", "친" },
	{ "太", "태" },
	{ "通", "통" },
	{ "特", "특" },
	{ "合", "합" },
	{ "行", "행, 항" },
	{ "向", "향" },
	{ "號", "호" },
	{ "畵", "화, 회" },
	{ "黃", "황" },
	{ "訓", "훈" }
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
	fputs("v0.5.0", stdout);
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
