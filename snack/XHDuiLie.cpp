#include "XHDuiLie.h"
#include<conio.h>
#include"cmath"
#include"time.h"

bool XHDuiLie::test(map1x& m) {
	static char i;
	static char lasti;
	if (_kbhit())
	{
		lasti = i;
		while (_kbhit())
			i = _getch();
		
		 
		 if (lasti == 'w'&&i=='s')
		 {
			 i = 'w';
		 }
		 if (lasti == 's' && i == 'w')
		 {
			 i = 's';
		 }
		 if (lasti == 'a' && i == 'd')
		 {
			 i = 'a';
		 }
		 if (lasti == 'd' && i == 'a')
		 {
			 i = 'd';
		 }
		 start = 0;

	}
	switch (i)
	{
	case 'w':
		--now.y;
		break;
	case 's':
		++now.y;
		break;
	case 'a':
		--now.x;
		break;
	case 'd':
		++now.x;
		break;
	default:
		break;
	}
	if (start==0&&m.Mapx[now.x][now.y] == 1)
	{
		return 1;
	}
	return 0;
}

void XHDuiLie::amend()
{
	now.x = now.x > 29 ? now.x - 30 : now.x;
	now.x = now.x < 0 ? now.x + 30 : now.x;
	
	now.y = now.y > 14 ? now.y - 15 : now.y;
	now.y = now.y < 0 ? now.y + 15 : now.y;
}

void XHDuiLie::push()
{
	amend();
	body[top].x = now.x;
	body[top].y = now.y;
	top++;
	top = top > 49 ? top - 50 : top;
}

void XHDuiLie::pop()
{
	amend();
	++bottom;
	bottom = bottom > 49 ? bottom - 50 : bottom;
	
}

bool XHDuiLie::ShowMap(map1x &m)
{	
	int num = 0;
	for (size_t i = bottom; i < bottom + length; i++)
	{
		int temp = i;
		temp = temp > 49 ? temp - 50 : temp;

		m.Mapx[body[temp].x][body[temp].y] = 1;

	}		
	 
	return true;
}

void XHDuiLie::FoodTest(map1x& m)
{
	LastLength = length;
	if (m.Mapx[now.x][now.y] == 2) {
		
		++length;
		FoodNum = 0;
	}
}


bool XHDuiLie::FoodTest(map1x& x,int y) {
	return x.Mapx[food.x][food.y] == y ? 1 : 0;
}

void XHDuiLie::FoodCreat(map1x& m)
{
	srand(time(NULL));
	if (!FoodNum)
	{
		do
		{
			food.x = rand() % 30;
			food.y = rand() % 15;
		} while (FoodTest(m,1));
		FoodNum = 1;
		m.Mapx[food.x][food.y] = 2;
	}
}
