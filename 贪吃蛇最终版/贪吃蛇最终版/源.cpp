
#include <string.h> //字符串处理
#include <windows.h>//包含有判断按键按下的状态的函数
#include <stdlib.h>//一些宏和通用工具函数
#include <conio.h>//控制台输入输出
#include <time.h>//定义关于时间的函数
#include <math.h>//定义数学函数
#include <iostream>//基本输入输出流
using namespace std;
#pragma warning(disable:4996)//忽略改警告 忽视warning，直接运行
#define de_lenth 5//蛇初始长度
#define Row_max 20//地图行
#define Line_max 20//地图列


class TCS
{
public:
	void Creatmap();//创造地图
	void Creatsnake();//创造蛇
	void Creatfood();//生成食物
	bool Judgewall();//判断是否撞墙
	void printmap();//打印地图
	void Late();//延时
	void Run();//蛇的运动
	void Movetail();//蛇身移动
	bool Eatfood();//判断是否吃掉食物
	void Result();//输出结果
	void SetPosition(int x, int y);//设置光标位置
	void changeSnake();//把尾巴移动到头的位置

private:
	char map[Row_max][Line_max];
	int snake[Row_max][Line_max];
	int Head_x = Line_max / 2;
	int Head_y = Row_max / 2;
	int Tail_x;
	int Tail_y;
	int Head_v = 5;//头部移动
	int timen = 5;//延时程度(蛇运动速度)
	int food_x;
	int food_y;
	int score = 0;//分数
	char direct = 's';//蛇的运动方向
};

void TCS::SetPosition(int x, int y)
{
	HANDLE winHandle;//句柄，指向系统的指针
	COORD pos = { x,y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置光标位置 
	SetConsoleCursorPosition(winHandle, pos);
}
void TCS::Creatmap()//画地图
{
	for (int i = 0; i < Row_max; i++)
	{
		for (int j = 0; j < Line_max; j++)
		{
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i <= Line_max - 1; ++i)
	{
		map[Row_max - 1][i] = '#';
		map[0][i] = '#';
	}
	for (int i = 1; i <= Row_max - 2; ++i)
	{
		map[i][0] = '#';
		map[i][Line_max - 1] = '#';
	}


}
void TCS::Creatsnake() //画蛇
{
	for (int i = 0; i < Row_max; i++)
	{
		for (int j = 0; j < Line_max; j++)
		{
			snake[i][j] = 0;
		}
	}
	int n = de_lenth;
	for (int i = Head_y; i >= Head_y - 5; --i)
	{
		snake[i][Head_x] = n--;
		if (i == Head_y - 5) //给蛇尾巴赋位置
		{
			Tail_y = i;
			Tail_x = Head_x;
		}
	}
}
void TCS::Creatfood()
{
	do
	{
		food_x = rand() % (Line_max - 2) + 1;//rand()%18+1会返回一个范围在1到19之间的伪随机数（整数）。
		food_y = rand() % (Row_max - 2) + 1;
	} while (snake[food_y][food_x] != 0 || map[food_y][food_x] == '#');
	{
		SetPosition(food_x, food_y);
		keybd_event(112, 0, 0, 0);
		keybd_event(112, 0, KEYEVENTF_KEYUP, 0);
		cout << "*";
		map[food_y][food_x] = '*';
		SetPosition(0, 0); }//打印食物
}
bool TCS::Eatfood() //判断是否吃到食物
{
	if (map[Head_y][Head_x] == '*')
	{
		map[Head_y][Head_x] = ' ';
		SetPosition(food_x, food_y);
		keybd_event(112, 0, 0, 0);
		keybd_event(112, 0, KEYEVENTF_KEYUP, 0);
		cout << " ";
		return true;
	}
	else
		return false;
}
bool TCS::Judgewall() //判断是否撞墙
{
	if (Head_x == 0 || Head_x == Line_max - 1 || Head_y == 0 || Head_y == Row_max - 1)
		return false; 
	else
		return true;
}
void TCS::printmap()
{
	for (int i = 0; i <= Row_max - 1; ++i)
	{
		for (int j = 0; j <= Line_max - 1; ++j) //地图和蛇一起打印
		{
			if (snake[i][j] == 0)cout << map[i][j];
			else
			{
				if (snake[i][j] == Head_v)
					cout << "Q";
				else
					cout << "*";
			}
		}
		cout << endl;
	}
}
void TCS::Movetail()//移动蛇身
{
	if (snake[Tail_y][Tail_x] + 1 == snake[Tail_y + 1][Tail_x])
	{
		snake[Tail_y][Tail_x] = 0;
		++Tail_y;
	}
	else if (snake[Tail_y][Tail_x] + 1 == snake[Tail_y - 1][Tail_x])
	{
		snake[Tail_y][Tail_x] = 0;
		--Tail_y;
	}
	else if (snake[Tail_y][Tail_x] + 1 == snake[Tail_y][Tail_x + 1])
	{
		snake[Tail_y][Tail_x] = 0;
		++Tail_x;
	}
	else
	{
		snake[Tail_y][Tail_x] = 0;
		--Tail_x;
	}
}
void TCS::Result()
{
	system("cls");
	cout << "游戏结束!" << endl;
	cout << "你的分数是：  " << score * 10 << " !" << endl;
	if (score <= 5)
		cout << "你的分数才这么点" << endl;
	else  if (score <= 15)
		cout << "一般般啊，勉强" << endl;
	else if (score >= 30)
		cout << "强，很秀" << endl;
	cout << "期待你下次的表现" << endl << "按任意键退出游戏" << endl;
	getch();
}
void TCS::Run()//蛇的移动
{
	/*
	上 -32 0xffffffe0 72 H
	下 -32 0xffffffe0 80 P
	左 -32 0xffffffe0 75 K
	右 -32 0xffffffe0 77 M
	*/
	//方向键为组合键
	char ch, sh;
	//打印地图
	printmap();
	while (1)
	{
		SetPosition(Head_x, Head_y);
		keybd_event(112, 0, 0, 0);
		keybd_event(112, 0, KEYEVENTF_KEYUP, 0);
		cout << "*";//模仿键盘

		if (Judgewall())
		{
			if (kbhit())//kbhit()函数判断键盘是否敲击，头文件"conio.h"
			{

				ch = getch();
				if (ch == -32)
				{
					sh = getch();
					if (direct == 'a')
					{
						if (sh == 'M')continue;
					}
					else if (direct == 'd')
					{
						if (sh == 'K')continue;
					}

					else if (direct == 'w')
					{
						if (sh == 'P')continue;
					}
					else
					{
						if (sh == 'H')continue;
					}


					//转头
					switch (sh)
					{
					case'H':direct = 'w';
						break;
					case'P':direct = 's';
						break;
					case'K':direct = 'a';
						break;
					case 'M':direct = 'd';
						break;
					}
				}
				else
				{
					if (direct == 'a')
					{
						if (ch == 'd' || ch == 'D')continue;
					}
					else if (direct == 'd')
					{
						if (ch == 'a' || ch == 'A')continue;
					}
					else if (direct == 'w')
					{
						if (ch == 's' || ch == 'S')continue;
					}
					else
					{
						if (ch == 'w' || ch == 'W')continue;
					}
					switch (ch)
					{
					case 'a':case 'A': direct = 'a'; break;
					case 'w':case 'W': direct = 'w'; break;
					case 's':case 'S': direct = 's'; break;
					case 'd':case 'D': direct = 'd'; break;
					}

				}
			}
			//蛇动一步
			if (direct == 'a')
			{
				if (snake[Head_y][Head_x - 1] != 0)
					return;//吃到自己
				--Head_x;

				if (Eatfood()) //如果吃到了食物，尾巴不动，并加分数
				{
					++score;
					int a = 1;
					a = a + 1;
					if (a % 3 == 0)
						++score;
					snake[Head_y][Head_x] = ++Head_v;
					Creatfood();
				}
				else //没吃到，只移动头和尾巴
				{
					snake[Head_y][Head_x] = ++Head_v;
					Movetail();
				}
			}
			else if (direct == 'd')
			{
				if (snake[Head_y][Head_x + 1] != 0)return;

				++Head_x;
				if (Eatfood())
				{
					++score;
					snake[Head_y][Head_x] = ++Head_v;
					Creatfood();
				}
				else
				{
					snake[Head_y][Head_x] = ++Head_v;
					Movetail();
				}
			}
			else if (direct == 'w')
			{
				if (snake[Head_y - 1][Head_x] != 0)return;

				--Head_y;
				if (Eatfood())
				{
					++score;
					snake[Head_y][Head_x] = ++Head_v;
					Creatfood();
				}
				else
				{
					snake[Head_y][Head_x] = ++Head_v;
					Movetail();
				}
			}
			else
			{
				if (snake[Head_y + 1][Head_x] != 0)return;
				++Head_y;
				if (Eatfood())
				{
					++score;
					snake[Head_y][Head_x] = ++Head_v;
					Creatfood();
				}
				else
				{
					snake[Head_y][Head_x] = ++Head_v;
					Movetail();
				}
			}
			//gotoxy(30, 30);

			//清屏

			//打印一次
			changeSnake();
			//延时
			Late();
			srand(time(NULL));
		}
		else
		{
			return;
		}
	}
}
void TCS::Late() //延时函数
{
	srand(time(NULL));
	Sleep(timen * 50);
}
void TCS::changeSnake()
{
	SetPosition(Tail_x, Tail_y);//光标移动到尾巴
	keybd_event(112, 0, 0, 0);//模拟按下 backspace
	keybd_event(112, 0, KEYEVENTF_KEYUP, 0);//模拟抬起
	cout << " ";

	SetPosition(Head_x, Head_y);//光标移动到头部
	keybd_event(112, 0, 0, 0);
	keybd_event(112, 0, KEYEVENTF_KEYUP, 0);
	cout << "Q";

};


int main()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态
	TCS tcs;
	cout << "   " << endl;
	cout << "   " << endl;
	cout << "按任意键开始游戏!" << endl;
	getch();
	tcs.Creatsnake();
	tcs.Creatmap();
	tcs.Creatfood();
	tcs.Run();
	tcs.Result();
	return 0;
}