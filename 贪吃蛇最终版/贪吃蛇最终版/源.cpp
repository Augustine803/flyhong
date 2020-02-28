
#include <string.h> //�ַ�������
#include <windows.h>//�������жϰ������µ�״̬�ĺ���
#include <stdlib.h>//һЩ���ͨ�ù��ߺ���
#include <conio.h>//����̨�������
#include <time.h>//�������ʱ��ĺ���
#include <math.h>//������ѧ����
#include <iostream>//�������������
using namespace std;
#pragma warning(disable:4996)//���Ըľ��� ����warning��ֱ������
#define de_lenth 5//�߳�ʼ����
#define Row_max 20//��ͼ��
#define Line_max 20//��ͼ��


class TCS
{
public:
	void Creatmap();//�����ͼ
	void Creatsnake();//������
	void Creatfood();//����ʳ��
	bool Judgewall();//�ж��Ƿ�ײǽ
	void printmap();//��ӡ��ͼ
	void Late();//��ʱ
	void Run();//�ߵ��˶�
	void Movetail();//�����ƶ�
	bool Eatfood();//�ж��Ƿ�Ե�ʳ��
	void Result();//������
	void SetPosition(int x, int y);//���ù��λ��
	void changeSnake();//��β���ƶ���ͷ��λ��

private:
	char map[Row_max][Line_max];
	int snake[Row_max][Line_max];
	int Head_x = Line_max / 2;
	int Head_y = Row_max / 2;
	int Tail_x;
	int Tail_y;
	int Head_v = 5;//ͷ���ƶ�
	int timen = 5;//��ʱ�̶�(���˶��ٶ�)
	int food_x;
	int food_y;
	int score = 0;//����
	char direct = 's';//�ߵ��˶�����
};

void TCS::SetPosition(int x, int y)
{
	HANDLE winHandle;//�����ָ��ϵͳ��ָ��
	COORD pos = { x,y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ù��λ�� 
	SetConsoleCursorPosition(winHandle, pos);
}
void TCS::Creatmap()//����ͼ
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
void TCS::Creatsnake() //����
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
		if (i == Head_y - 5) //����β�͸�λ��
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
		food_x = rand() % (Line_max - 2) + 1;//rand()%18+1�᷵��һ����Χ��1��19֮���α���������������
		food_y = rand() % (Row_max - 2) + 1;
	} while (snake[food_y][food_x] != 0 || map[food_y][food_x] == '#');
	{
		SetPosition(food_x, food_y);
		keybd_event(112, 0, 0, 0);
		keybd_event(112, 0, KEYEVENTF_KEYUP, 0);
		cout << "*";
		map[food_y][food_x] = '*';
		SetPosition(0, 0); }//��ӡʳ��
}
bool TCS::Eatfood() //�ж��Ƿ�Ե�ʳ��
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
bool TCS::Judgewall() //�ж��Ƿ�ײǽ
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
		for (int j = 0; j <= Line_max - 1; ++j) //��ͼ����һ���ӡ
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
void TCS::Movetail()//�ƶ�����
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
	cout << "��Ϸ����!" << endl;
	cout << "��ķ����ǣ�  " << score * 10 << " !" << endl;
	if (score <= 5)
		cout << "��ķ�������ô��" << endl;
	else  if (score <= 15)
		cout << "һ��㰡����ǿ" << endl;
	else if (score >= 30)
		cout << "ǿ������" << endl;
	cout << "�ڴ����´εı���" << endl << "��������˳���Ϸ" << endl;
	getch();
}
void TCS::Run()//�ߵ��ƶ�
{
	/*
	�� -32 0xffffffe0 72 H
	�� -32 0xffffffe0 80 P
	�� -32 0xffffffe0 75 K
	�� -32 0xffffffe0 77 M
	*/
	//�����Ϊ��ϼ�
	char ch, sh;
	//��ӡ��ͼ
	printmap();
	while (1)
	{
		SetPosition(Head_x, Head_y);
		keybd_event(112, 0, 0, 0);
		keybd_event(112, 0, KEYEVENTF_KEYUP, 0);
		cout << "*";//ģ�¼���

		if (Judgewall())
		{
			if (kbhit())//kbhit()�����жϼ����Ƿ��û���ͷ�ļ�"conio.h"
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


					//תͷ
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
			//�߶�һ��
			if (direct == 'a')
			{
				if (snake[Head_y][Head_x - 1] != 0)
					return;//�Ե��Լ�
				--Head_x;

				if (Eatfood()) //����Ե���ʳ�β�Ͳ��������ӷ���
				{
					++score;
					int a = 1;
					a = a + 1;
					if (a % 3 == 0)
						++score;
					snake[Head_y][Head_x] = ++Head_v;
					Creatfood();
				}
				else //û�Ե���ֻ�ƶ�ͷ��β��
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

			//����

			//��ӡһ��
			changeSnake();
			//��ʱ
			Late();
			srand(time(NULL));
		}
		else
		{
			return;
		}
	}
}
void TCS::Late() //��ʱ����
{
	srand(time(NULL));
	Sleep(timen * 50);
}
void TCS::changeSnake()
{
	SetPosition(Tail_x, Tail_y);//����ƶ���β��
	keybd_event(112, 0, 0, 0);//ģ�ⰴ�� backspace
	keybd_event(112, 0, KEYEVENTF_KEYUP, 0);//ģ��̧��
	cout << " ";

	SetPosition(Head_x, Head_y);//����ƶ���ͷ��
	keybd_event(112, 0, 0, 0);
	keybd_event(112, 0, KEYEVENTF_KEYUP, 0);
	cout << "Q";

};


int main()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ
	CursorInfo.bVisible = false; //���ؿ���̨���
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬
	TCS tcs;
	cout << "   " << endl;
	cout << "   " << endl;
	cout << "���������ʼ��Ϸ!" << endl;
	getch();
	tcs.Creatsnake();
	tcs.Creatmap();
	tcs.Creatfood();
	tcs.Run();
	tcs.Result();
	return 0;
}