#include "File.h"
#include <fstream>  

using namespace std;

/*
0	��ͨ�ļ����򿪲���
1	ֻ���ļ�
2	�����ļ�
4	ϵͳ�ļ�
*/
int Save(int map[GRIDSIZE][GRIDSIZE], int next)
{
	std::ofstream out;
	out.open(FILE_NAME, ios_base::out|ios::trunc);

	if(out.is_open())
	{
		for(int x=0; x<GRIDSIZE; ++x)
		{
			for(int y=0;y<GRIDSIZE; ++y)
			{
				out<<map[x][y]<<std::endl;
			}
		}

		out.close();
		return 0;
	}

	return -1;//����ʧ��
}

int Read(int (*map)[GRIDSIZE][GRIDSIZE], int *next)
{	
	std::ifstream in;
	in.open(FILE_NAME, ios_base::in);

	if (in.is_open())  
	{
		for(int x=0; x<GRIDSIZE; ++x)
		{
			for(int y=0;y<GRIDSIZE; ++y)
			{
				if(!in.eof())
				{
					in>>(*map)[x][y];
				}
			}
		}

		in.close();
		return 0;
	}

	return -1;//��ȡʧ��
}
