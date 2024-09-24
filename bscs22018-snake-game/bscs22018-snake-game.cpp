#include <iostream>
#include<conio.h>
#include<fstream>
#include<Windows.h>
#include<ctime>
#include<time.h>
using namespace std;
enum DIRECTION { UP, DOWN, LEFT, RIGHT };
struct position {
	int r;
	int c;
};
struct Snake {
	position* SP;
	int score;
	int size;
	DIRECTION dir;
	bool isalive;
	char S_sym;
	int UPKEY, DOWNKEY, RIGHTKEY, LEFTKEY;
};
struct Food {
	position FP;

	//int score;
	char F_sym;

};

void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}
void gotoRowCol(int rpos, int cpos)
{
	COORD scrn = {};
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}
void SetClr(int clr)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}



void init(Snake*& S,int num, Food& F, int h, int w)
{
	for (int j = 0; j < num; j++)
	{
		S[j].SP = new position[10];
		for (int i = 0; i < 2; i++)
		{
			S[j].SP[0].r = h / 2 + j;
			S[j].SP[0].c = w / 2 - i;
		}
		S[j].size = 3;
		S[j].score = 0;
		S[j].S_sym = -37;
		S[j].dir = RIGHT;
		S[j].isalive = true;
	}
	if (num <= 1) {
		S[0].RIGHTKEY = 77, S[0].LEFTKEY = 75, S[0].UPKEY = 72, S[0].DOWNKEY = 80;
	}
	if (num <= 2) {
		S[1].RIGHTKEY = 115, S[1].LEFTKEY = 97, S[1].UPKEY = 119, S[1].DOWNKEY = 122;
	}
	if (num <= 3) {
		S[2].RIGHTKEY = 107, S[2].LEFTKEY = 106, S[2].UPKEY = 105, S[2].DOWNKEY = 109;
	}if (num <= 4) {
		S[3].RIGHTKEY = 104, S[3].LEFTKEY = 103, S[3].UPKEY = 121, S[3].DOWNKEY = 98;
	}
	F.F_sym = '*';
}
void erase_Snake(Snake*& S,int num)
{
	for (int j = 0; j < num; j++)
	{
		if (S[j].isalive)
		{
			for (int i = 0; i < S[j].size; i++)
			{
				gotoRowCol(S[j].SP[i].r, S[j].SP[i].c);
				cout << " ";
			}
		}
	}
}
void display_Snake(Snake*& S,int num)
{

	for (int j = 0; j < num; j++)
	{
		if (j == 0)
		{
			SetClr(6);
		}
		else if (j == 1)
		{
			SetClr(4);
		}
		else if (j == 2)
		{
			SetClr(3);
		}
		else if (j == 3)
			SetClr(11);
		if (S[j].isalive)
		{
			for (int i = 0; i < S[j].size; i++)
			{
				gotoRowCol(S[j].SP[i].r, S[j].SP[i].c);
				cout << S[j].S_sym;
			}
		}
	}
}
void changeDirection(Snake& S, char key)
{
	if (key == S.RIGHTKEY)
	{
		if (S.dir != LEFT)
			S.dir = RIGHT;
	}
	else if (key == S.LEFTKEY)
	{
		if (S.dir != RIGHT)
			S.dir = LEFT;
	}
	else if (key == S.UPKEY)
	{
		if (S.dir != DOWN)
			S.dir = UP;
	}
	else if (key == S.DOWNKEY)
	{
		if (S.dir != UP)
			S.dir = DOWN;
	}
}
bool move_Snake_1(Snake*& S, int h, int w,int num)
{
	for (int j = 0; j < num; j++)
	{
		if (S[j].isalive == true)
		{
			for (int i = S[j].size - 1; i - 1 >= 0; i--)
			{
				S[j].SP[i] = S[j].SP[i - 1];
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (S[i].isalive == 1)
		{
			switch (S[i].dir)
			{
			case UP:
			{
				S[i].SP[0].r--;
				if (S[i].SP[0].r == 0)
				{
					S[i].isalive = false;
					return true;
				}
				break;
			}
			case DOWN:
			{
				S[i].SP[0].r++;
				if (S[i].SP[0].r == h)
				{
					S[i].isalive = false;
					return true;
				}
				break;
			}
			case RIGHT:
			{
				S[i].SP[0].c++;
				if (S[i].SP[0].c == w)
				{
					S[i].isalive = false;
					return true;
				}
				break;
			}
			case LEFT:
			{
				S[i].SP[0].c--;
				if (S[i].SP[0].c == 0)
				{
					S[i].isalive = false;
					return true;
				}
				break;
			}
			}
		}
	}
	return false;
}
bool move_Snake_2(Snake*& S, int h, int w,int num)
{
	for (int j = 0; j < num; j++)
	{
		if (S[j].isalive == true)
		{
			for (int i = S[j].size - 1; i - 1 >= 0; i--)
			{
				S[j].SP[i] = S[j].SP[i - 1];
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (S[i].isalive == 1)
		{
			switch (S[i].dir)
			{
			case UP:
			{
				S[i].SP[0].r--;
				if (S[i].SP[0].r == h / 2)
				{
					S[i].isalive = false;
					return true;
				}
				else if (S[i].SP[0].r == 0)
					S[i].SP[0].r = h - 1;
				break;
			}
			case DOWN:
			{
				S[i].SP[0].r++;
				if (S[i].SP[0].r == h / 2)
				{
					S[i].isalive = false;
					return true;
				}
				else if (S[i].SP[0].r == h)
					S[i].SP[0].r = 0;
				break;
			}
			case RIGHT:
			{
				S[i].SP[0].c++;
				if (S[i].SP[0].c == w / 2)
				{
					S[i].isalive = false;
					return true;
				}
				else if (S[i].SP[0].c == w)
				{
					S[i].SP[0].c = 0;
				}
				break;
			}
			case LEFT:
			{
				S[i].SP[0].c--;
				if (S[i].SP[0].c == w / 2)
				{
					S[i].isalive = false;
					return true;
				}
				else if (S[i].SP[0].c == 0)
				{
					S[i].SP[0].c = w - 1;
				}
				break;
			}
			}
		}
	}
	return false;
}
void move_Snake(Snake*& S, int h, int w,int num)
{
	for (int j = 0; j < num; j++)
	{
		if (S[j].isalive == true)
		{
			for (int i = S[j].size - 1; i - 1 >= 0; i--)
			{
				S[j].SP[i] = S[j].SP[i - 1];
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (S[i].isalive == 1)
		{
			switch (S[i].dir)
			{
			case UP:
			{
				S[i].SP[0].r--;
				if (S[i].SP[0].r == -1)
					S[i].SP[0].r = h;
				break;
			}
			case DOWN:
			{
				S[i].SP[0].r++;
				if (S[i].SP[0].r == h)
					S[i].SP[0].r = 0;
				break;
			}
			case RIGHT:
			{
				S[i].SP[0].c++;
				if (S[i].SP[0].c == w)
					S[i].SP[0].c = 0;
				break;
			}
			case LEFT:
			{
				S[i].SP[0].c--;
				if (S[i].SP[0].c == -1)
					S[i].SP[0].c = w;
				break;
			}
			}
		}
	}
}
bool islegalcoordinate(position p, Snake& S)
{

	for (int i = 0; i < S.size; i++)
	{
		if (S.SP[i].r == p.r && S.SP[i].c == p.c)
		{
			return false;
		}
	}

	return true;
}
void generate_Food(Food& f, int h, int w, Snake*& S,int num)
{
	SetClr(9);
	for (int i = 0; i < num; i++)
	{
		if (S[i].isalive)
		{

			do
			{
				f.FP.r = rand() % h;
				f.FP.c = rand() % w;
			} while (!islegalcoordinate(f.FP, S[i]));
		}
	}
	gotoRowCol(f.FP.r, f.FP.c);
	cout << f.F_sym;
}
void generate_Food_1(Food& f, int h, int w, Snake*& S,int num)
{
	h = h - 2;
	w = w - 2;
	SetClr(9);
	for (int i = 0; i < num; i++)
	{
		if (S[i].isalive)
		{

			do
			{
				f.FP.r = rand() % (h);
				f.FP.c = rand() % (w);
			} while (!islegalcoordinate(f.FP, S[i]));
		}
	}
	f.FP.r = f.FP.r + 1, f.FP.c = f.FP.c + 1;
	gotoRowCol(f.FP.r, f.FP.c);
	cout << f.F_sym;
}
void generate_Food_2(Food& f, int h, int w, Snake*& S,int num)
{
	SetClr(9);
	for (int i = 0; i < num; i++)
	{
		if (S[i].isalive)
		{

			do
			{
				f.FP.r = rand() % h - 2;
				f.FP.c = rand() % w - 2;
			} while (!islegalcoordinate(f.FP, S[i]) && f.FP.r != h / 2 && f.FP.c != w / 2);
		}
	}
	gotoRowCol(f.FP.r, f.FP.c);
	cout << f.F_sym;
}
bool isFood_Eaten(Food& f, Snake*& S,int num)
{
	for (int i = 0; i < num; i++)
	{
		if (S[i].SP[0].r == f.FP.r && S[i].SP[0].c == f.FP.c)
		{
			S[i].score++; S[i].size++;
			return true;
		}
	}
	return false;
}
bool Khudkushi(Snake*& S,int num)
{
	for (int i = 0; i < num; i++)
	{
		if (S[i].isalive)
		{
			for (int j = 1; j < S[i].size; j++)
			{
				if (S[i].SP[j].r == S[i].SP[0].r && S[i].SP[j].c == S[i].SP[0].c)
				{
					S[i].isalive = false;
					return true;
				}
			}
		}
	}
	return false;
}
void boundary(int h, int w)
{
	SetClr(1);
	char sym = -37;
	for (int i = 0; i < w; i++)
	{
		cout << sym;
	}
	gotoRowCol(0, 0);
	for (int i = 0; i < h; i++)
	{
		cout << sym;
		cout << endl;
	}
	gotoRowCol(h - 1, 0);
	for (int i = 0; i < w; i++)
	{
		cout << sym;
	}
	for (int i = 0; i < h; i++)
	{
		gotoRowCol(i, w);
		cout << sym;
	}

}
void level_1_duniya_Gol_Hy()
{
	srand(time(0));
	int num;
	do {
		cout << "\nHow many players you want to play(1 to 4) : "; cin >> num;
	} while (num < 0 && num>4);
	Snake* S = new Snake[num]{};
	Food F;
	system("cls");
	int height = 60;
	int width = 80;
	char ch;
	init(S, num,F, height / 2, width / 2);
	for (int i = 0; i < num; i++)
	{
		gotoRowCol(3 + i, 100);
		cout << "SCORE : " << S[i].score;
	}
	generate_Food(F, height, width, S,num);
	int sum = 0;
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			if ((ch == -32) && num >= 1)
			{
				ch = _getch();
				changeDirection(S[0], ch);
			}
			else if ((ch == 97 || ch == 115 || ch == 119 || ch == 122) && num >= 2)
			{
				changeDirection(S[1], ch);
			}
			else if ((ch == 106 || ch == 107 || ch == 105 || ch == 109) && num >= 3)
			{
				changeDirection(S[2], ch);
			}
			else if ((ch == 104 || ch == 103 || ch == 121 || ch == 98) && num == 4)
				changeDirection(S[3], ch);
		}
		if (isFood_Eaten(F, S,num) == 1)
		{
			//PlaySound(TEXT("bscs22018-food.wav"), NULL, SND_SYNC);
			erase_Snake(S,num);
			display_Snake(S,num);
			generate_Food(F, height, width, S,num);
			for (int i = 0; i < num; i++)
			{
				gotoRowCol(3 + i, 100);
				cout << "SCORE : " << S[i].score;
			}
		}
		display_Snake(S,num);
		Sleep(50);
		erase_Snake(S,num);
		move_Snake(S, height, width,num);
		if (Khudkushi(S,num))
		{
			sum++;
			if (sum == 4)
				break;
		}

	}
	gotoRowCol(1, 50);
	cout << "Game Over!!!!!!!";
	for (int i = 0; i < num; i++)
	{
		gotoRowCol(3 + i, 50);
		cout << "SCORE : " << S[i].score;
	}
}
void level_2_Complete_Bondary()
{
	srand(time(0));
	int num;
	do {
		cout << "\nHow many players you want to play(1 to 4) : "; cin >> num;
	} while (num < 0 && num>4);
	Snake* S = new Snake[num]{};
	system("cls");
	Food F;
	int height = 60;
	int width = 80;
	boundary(height, width);
	char ch;
	init(S,num, F, height / 2, width / 2);
	generate_Food_1(F, height, width, S,num);
	for (int i = 0; i < num; i++)
	{
		gotoRowCol(3 + i, 100);
		cout << "Score :  " << S[i].score;
	}
	int sum = 0;
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == -32 && num>=1)
			{
				ch = _getch();
				changeDirection(S[0], ch);
			}
			else if ((ch == 97 || ch == 115 || ch == 119 || ch == 122) && num>=2)
			{
				changeDirection(S[1], ch);
			}
			else if ((ch == 106 || ch == 107 || ch == 105 || ch == 109) && num>=3 )
			{
				changeDirection(S[2], ch);
			}
			else if ((ch == 104 || ch == 103 || ch == 121 || ch == 98) && num==4)
				changeDirection(S[3], ch);
		}
		display_Snake(S,num);
		if (isFood_Eaten(F, S,num))
		{
			//PlaySound(TEXT("bscs22018-food.wav"), NULL, SND_SYNC);
			erase_Snake(S,num);
			display_Snake(S,num);
			generate_Food_1(F, height, width, S,num);
			for (int i = 0; i < num; i++)
			{
				gotoRowCol(3 + i, 100);
				cout << "Score :  " << S[i].score;
			}
		}
		Sleep(50);
		erase_Snake(S,num);
		if (move_Snake_1(S, height, width,num) || Khudkushi(S,num))
		{
			sum++;
			if (sum == 4)
				break;
		}
	}
	system("cls");
	gotoRowCol(1, 50);
	cout << " Game Over!!!!!!!!!";
	for (int i = 0; i < num; i++)
	{
		gotoRowCol(4 + i, 50);
		cout << "Score : " << S[i].score;
	}
	cout << endl << endl;
}
void boundary_Plus(int h, int  w)
{
	SetClr(1);
	char sym = -37;
	for (int i = 0; i < h; i++)
	{
		gotoRowCol(i, w / 2);
		cout << sym;
	}
	for (int i = 0; i < w; i++)
	{
		gotoRowCol(h / 2, i);
		cout << sym;
	}
}
void level_3_Plus_Bondary()
{
	srand(time(0));
	int num;
	do {
		cout << "\nHow many players you want to play(1 to 4) : "; cin >> num;
	} while (num < 0 && num>4);
	Snake* S = new Snake[num]{};
	system("cls");
	Food F;
	int height = 60;
	int width = 80;
	boundary_Plus(height, width);
	char ch;
	init(S,num, F, height / 2, width / 2);
	generate_Food_2(F, height, width, S,num);
	for (int i = 0; i < num; i++)
	{
		gotoRowCol(3 + i, 100);
		cout << "Score : " << S[i].score;
	}
	int sum = 0;
	while (true)
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == -32 && num >= 1)
			{
				ch = _getch();
				changeDirection(S[0], ch);
			}
			else if ((ch == 97 || ch == 115 || ch == 119 || ch == 122) && num >= 2)
			{
				changeDirection(S[1], ch);
			}
			else if ((ch == 106 || ch == 107 || ch == 105 || ch == 109) && num >= 3)
			{
				changeDirection(S[2], ch);
			}
			else if ((ch == 104 || ch == 103 || ch == 121 || ch == 98) && num == 4)
				changeDirection(S[3], ch);
		}
		if (isFood_Eaten(F, S,num))
		{
		//	PlaySound(TEXT("bscs22018-food.wav"), NULL, SND_SYNC);
			erase_Snake(S,num);
			display_Snake(S,num);
			generate_Food_2(F, height, width, S,num);
			for (int i = 0; i < num; i++)
			{
				gotoRowCol(3 + i, 100);
				cout << "Score :  " << S[i].score;
			}
		}
		display_Snake(S,num);
		Sleep(50);
		erase_Snake(S,num);
		if (move_Snake_2(S, height, width,num) || Khudkushi(S,num))
		{
			sum += 1;
			if (sum == 4)
				break;
		}
	}
	system("cls");
	gotoRowCol(1, 50);
	cout << " Game Over!!!!!!!!!";
	for (int i = 0; i < num; i++)
	{
		gotoRowCol(3 + i, 50);
		cout << "Score : " << S[i].score;
	}
}

//void vertical(int s,int c, int l)
//{
//	for (int i = 0; i < l; i++)
//	{
//		gotoRowCol(s + i, c);
//	}
//}
//void horizontal(int s, int r, int l)
//{
//	for (int i = 0; i < l; i++)
//	{
//		gotoRowCol(r, s+i);
//	}
//}
void Snake_Pic()
{
	gotoRowCol(7, 5);
	cout << "   _____ _   _          _  ________ ";
	gotoRowCol(8, 5);
	cout << "  / ____| \\ | | /\\   | |/ /  ____| ";
	gotoRowCol(9, 5);
	cout << " | (___ | \\||  / \\  | ' /| |__    ";
	gotoRowCol(10, 5);
	cout << "  \___\\| . ` | / /\\\ |  < |  __|  ";
	gotoRowCol(11, 5);
	cout << "  ____) |\\  |/ ____\\| .\\| |____ ";
	gotoRowCol(12, 5);
	cout << " |_____/|_|\\_/_/    \\_\\_|\\_\\______|";
}
void  Interface(int& ch)
{
	const int hl = 60;
	const int wl = 80;
	Snake_Pic();
	gotoRowCol(hl / 2, wl / 2);
	cout << "ENTER MODE TO DISPLAY : ";
	gotoRowCol(hl / 2 + 1, wl / 2);
	cout << "Level 1 Duniya Gol hy : ";
	gotoRowCol(hl / 2 + 2, wl / 2);
	cout << "Level 2 Complete Boundary: ";
	gotoRowCol(hl / 2 + 3, wl / 2);
	cout << "Level 3 Boundary Having Plus Sign: ";
	cin >> ch;
	system("cls");
}
int main()
{
	/*while (1) {
		char ch = _getch();
		cout << int(ch) << "  ";
	}*/
	int ch = 0;
	Interface(ch);
	switch (ch)
	{
	case(1):
	{
		level_1_duniya_Gol_Hy();
		break;
	}
	case(2):
	{
		level_2_Complete_Bondary();
		break;
	}
	case(3):
	{
		level_3_Plus_Bondary();
		break;
	}
	}
	return 0;
}
