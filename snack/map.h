#pragma once
#include"Windows.h"
void moveCursor(SHORT x, SHORT y);
extern bool start;
struct position
{
public:
	int x;
	int y;
};

class map1x
{
public:
	map1x();
	~map1x() {};
	int Mapx[30][15];
	int LastMapx[30][15];
	bool compare(int x,int y);
	void show();
	void clean();
	
	

	
	
};








