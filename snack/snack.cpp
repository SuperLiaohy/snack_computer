#include<Windows.h>
#include<stdlib.h>
#include <iostream>
#include"map.h"
#include"XHDuiLie.h"
void hideCursor() {
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = 0;
	cursor.dwSize = 1;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hOut, &cursor);
}
XHDuiLie body;
map1x MAP1;
using namespace std;
int main()
{
	hideCursor();
	body.push();

	body.ShowMap(MAP1);
	
	body.FoodCreat(MAP1);
	
	MAP1.show();
	
	while (true)
	{
		
		if (body.test(MAP1)) {
			break;
		}
		MAP1.clean();
		body.ShowMap(MAP1);

		body.FoodTest(MAP1);
		
		if (body.LastLength == body.length)
		{
			body.push();
			body.pop();
		}
		else {
			body.push();
		}
		
		body.FoodCreat(MAP1);
		
		MAP1.show();
		moveCursor(1, 15);
		printf("得分：%d", body.length);
		Sleep(100);
	}
	moveCursor(1, 16);
	printf("结束");
	getchar();
	return 0;
}

