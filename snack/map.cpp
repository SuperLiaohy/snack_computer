#include"map.h"
#include"cmath"
#include"stdio.h"


bool start = 1;
void moveCursor(SHORT x, SHORT y) {
	COORD pos = { x, y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}
bool map1x::compare(int x, int y)
{
	return LastMapx[x][y] == Mapx[x][y] ? 0 : 1;
}

void map1x::show()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 30; j++) {
			if (compare(j,i))
			{
				moveCursor(j, i);
				switch (Mapx[j][i])
				{
				case 0:
					printf(" ");
						break;
				case 1:
					printf("o");
						break;
				case 2:
					printf("$");
					break;
				default:
					break;
				}
			}
			
			
		}
		printf("\n");
	}
}
void map1x::clean()
{
	static int val = 2;
	for (size_t i = 0; i < 30; i++)
	{
		for (size_t j = 0; j < 15; j++)
		{
			if (val)
			{
				LastMapx[i][j] = 0;
				if (start==0)
				{
					val--;
				}
			} else
			{
				LastMapx[i][j] = Mapx[i][j];
			}
			
			Mapx[i][j] = Mapx[i][j]==1?0:Mapx[i][j];
		}

	}
}
map1x::map1x()
{
	
	for (size_t i = 0; i < 30; i++)
	{
		for (size_t j = 0; j < 15; j++)
		{
			Mapx[i][j] = 0;
		}

	}
}
