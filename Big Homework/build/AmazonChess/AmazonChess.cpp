// AmazonChess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <graphics.h>
#include <conio.h>

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "game.h"

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int ret = 0;

	ret = ShowMenu();
	do
	{
		if(ret == 1)
		{
			ret = NewGame();
			continue;
		}		

		if(ret == 2)
		{
			ret = LoadChess();
			continue;
		}

		if(ret == 3)
		{
			SaveChess();
			ret = ShowMenu();
		}

		if(ret == 4)
		{
			break;//ÍË³ö³ÌÐò
		}

	}while(true);

	return 0;
}

