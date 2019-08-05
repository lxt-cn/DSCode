#pragma once

#include "Stack.h"

//   һ���Թ�						��ͨ·������				��ͨ·����
//   0 0 0 0 0 0					0 0 0 0 0 0					0 0 0 0 0 0 	
//   0 0 1 0 0 0					0 0 1 1 1 1					0 0 1 1 1 0 	
//   0 0 1 0 0 0					0 0 1 0 0 0					0 0 1 0 1 0 	
//   0 0 1 1 1 0					0 0 1 0 0 0					0 0 1 0 1 0 	
//   0 0 1 0 1 1					0 0 1 1 1 1					0 0 1 1 1 1 	
//   0 0 1 0 0 0					0 0 1 0 0 0					0 0 1 0 0 0 	

#define N 6
static int SimpleMaze[N][N] = {
	{0,0,0,0,0,0},
	{0,0,1,0,0,0},
	{0,0,1,0,0,0},
	{0,0,1,1,1,0},
	{0,0,1,0,1,1},
	{0,0,1,0,0,0},
};

static int MiddleMaze[N][N] = {
	{0,0,0,0,0,0},
	{0,0,1,1,1,1},
	{0,0,1,0,0,0},
	{0,0,1,0,0,0},
	{0,0,1,1,1,1},
	{0,0,1,0,0,0},
};

static int DifficultMaze[N][N] = {
	{0,0,0,0,0,0},
	{0,0,1,1,1,0},
	{0,0,1,0,1,0},
	{0,0,1,0,1,0},
	{0,0,1,1,1,1},
	{0,0,1,0,0,0},
};

int GetSimpleMazePath(Pos entry, Pos exit);
int GetMiddleMazePath(Pos entry);
int GetDifficultMazePath(Pos entry);
int CheckAccess(int maze[N][N], Pos next);
int CheckAccessUp(Pos cur, Pos next);
void PrintMaze(int maze[N][N]);

void TestMaze();
