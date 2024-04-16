#pragma once

#include "map.h"

class XHDuiLie
{
public:

	int length;
	position now;

	void amend();
	void pop();

	void push();

	bool ShowMap(map1x& m);

    position food;
	bool FoodNum;
	void FoodCreat(map1x& x);
	bool FoodTest(map1x& x,int y);
	

	

	void FoodTest(map1x &m);

	bool test(map1x&m);
	
	XHDuiLie() {
		FoodNum = 0;
		bottom = 0;
		top = 0;
		length = 1;
		now.x=0;
		now.y = 0;
	};

	int LastLength;

private:
	position body[50];
	
	int top;
	int bottom;
	

};



