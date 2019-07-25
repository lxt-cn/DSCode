#include "Maze.h"
#include "Stack.h"

int CheckAccess(Pos next)
{
	if (next._row >= 0 && next._row < N
		&& next._col >= 0 && next._col < N
		&& maze[next._row][next._col] == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int GetMazePath(Pos entry, Pos exit)
{
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);

	while (StackEmpty(&path))
	{
		Pos cur = StackTop(&path);
		Pos next;

		maze[cur._row][cur._col] = 2;
		if (cur._row == exit._row
			&& cur._col == exit._col)
		{
			// 出口
			StackDestory(&path);
			return 1;
		}
	
		// 探测下一个去的位置
		// 上
		next = cur;
		next._row -= 1;
		if(CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}

		// 下
		next = cur;
		next._row += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}

		// 左
		next = cur;
		next._col -= 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}

		// 右
		next = cur;
		next._col += 1;
		if (CheckAccess(next))
		{
			StackPush(&path, next);
			continue;
		}

		// 回溯
		StackPop(&path);
	}
	return 0;
}

void PrintMaze()
{
	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < N; ++j)
		{
			printf("%d", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void TestMaze()
{
	Pos entry;
	Pos exit;
	entry._row = 5;
	entry._col = 2;

	exit._row = 4;
	exit._col = 5;

	PrintMaze();
	printf("是否有出口?:%d\n", GetMazePath(entry, exit));
	PrintMaze();
}
