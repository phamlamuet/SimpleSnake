#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<windows.h>
#include"console.h"
#include<ctime>
using namespace std;
int chieucao = 20, chieurong = 45, score = 0;
bool GameOver=false;
enum TRANGTHAI
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STOP
};
struct Toa_Do // chua toa do cua 1 o trong man hinh
{
	int x, y;
};
Toa_Do Food;
struct Snake
{
	int n; // do dai con ran
	Toa_Do Than[200];
	TRANGTHAI tt; // bien tt luu trang thai cua con ran
};
void Print_Snake(Snake snake)
{
	for (int i = 0; i < snake.n; i++)
	{
		gotoXY(snake.Than[i].x, snake.Than[i].y);
		cout << "@";
	}
}
void XuLyDiChuyen(Snake &snake)
{
	for (int i = snake.n - 1; i > 0; i--)
	{
		snake.Than[i].x = snake.Than[i - 1].x;
		snake.Than[i].y = snake.Than[i - 1].y;
	}
}
void Draw()
{
	for (int i = 0; i < chieucao; i++)
	{
		for (int j = 0; j < chieurong; j++)
			if (i == 0 || i == chieucao - 1 || j == 0 || j == chieurong - 1)
				cout << (char)254;
			else cout << " ";
		cout << endl;
	}
	cout << "SCORE:" << score << endl;
	cout << "CLASSIC-SNAKE-GAME-CODE-BY-LAM" << endl;
}
void SetUp(Toa_Do Food)
{
	gotoXY(Food.x, Food.y);
		cout << "F";
}
void Logic(Snake &snake)
{
	if (snake.Than[0].x == Food.x && snake.Than[0].y == Food.y)
	{
		score += 10;
		srand(time(NULL));
		Food.x = 5+rand()%(chieurong-2+1-5);
		Food.y = 5+rand() % (chieucao-2+1-5);
		snake.n++;
	}
	if (snake.Than[0].x == chieurong|| snake.Than[0].y == chieucao-1 || snake.Than[0].x == 0 || snake.Than[0].y == 0)
	{
		GameOver = true;
	}

	
}
int main()
{
	Snake snake;
	snake.n = 1;
	snake.Than[0].x = 2;
	snake.Than[0].y = 2;
	Food.x = 5 + rand() % (chieurong - 2 + 1 - 5);
	Food.y = 5 + rand() % (chieucao - 2 + 1 - 5);
	
	
	while (!GameOver)
	{
		clrscr();
		Draw();
		SetUp(Food);
		Print_Snake(snake);
		if (_kbhit())
		{
			char key = _getch();
			switch (key)
			{
			case 'w':
			case 'W':
			{
				if (snake.tt != DOWN)
					snake.tt = UP;
				break;
			}
			case 's':
			case 'S':
			{  if (snake.tt != UP)
				snake.tt = DOWN;
			break;
			}
			case 'a':
			case 'A':
			{
				if (snake.tt != RIGHT)
					snake.tt = LEFT;
				break;
			}
			case 'd':
			case 'D':
			{
				if (snake.tt != LEFT)
					snake.tt = RIGHT;
				break;
			}
			}
		}
		XuLyDiChuyen(snake);
		switch (snake.tt)
		{
		case UP:snake.Than[0].y--; break;
		case DOWN:snake.Than[0].y++; break;
		case LEFT:snake.Than[0].x--; break;
		case RIGHT:snake.Than[0].x++; break;
		}
		Logic(snake);
		for (int i = 1; i < snake.n; i++)
		{
			if (snake.Than[i].x == snake.Than[0].x&&snake.Than[i].y == snake.Than[0].y)
				GameOver = true;
		}
		Sleep(300);
	}
}