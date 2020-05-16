#ifndef FILE_H
#define FILE_H

#define FILE_NAME "RECORD.DAT"
#define GRIDSIZE 8

int Save(int map[GRIDSIZE][GRIDSIZE], int next);
int Read(int (*map)[GRIDSIZE][GRIDSIZE], int *next);

#endif