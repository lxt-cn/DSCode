#include "Maze.h"
#include "Stack.h"

int CheckAccess(int maze[N][N], Pos next)
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
int GetSimpleMazePath(Pos entry, Pos exit)
{
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);

	while (StackEmpty(&path))
	{
		Pos cur = StackTop(&path);
		Pos next;

		SimpleMaze[cur._row][cur._col] = 2;
		if (cur._row == exit._row
			&& cur._col == exit._col)
		{
			// 出口

			// 只找一条通路
			StackDestory(&path);
			return 1;
		}

		// 探测下一个去的位置
		// 上
		next = cur;
		next._row -= 1;
		if (CheckAccess(SimpleMaze, next))
		{
			StackPush(&path, next);
			continue;
		}

		// 下
		next = cur;
		next._row += 1;
		if (CheckAccess(SimpleMaze, next))
		{
			StackPush(&path, next);
			continue;
		}

		// 左
		next = cur;
		next._col -= 1;
		if (CheckAccess(SimpleMaze, next))
		{
			StackPush(&path, next);
			continue;
		}

		// 右
		next = cur;
		next._col += 1;
		if (CheckAccess(SimpleMaze, next))
		{
			StackPush(&path, next);
			continue;
		}

		// 回溯
		StackPop(&path);
	}
	return 0;
}

Stack minpath;
int pathsize = 0;

int GetMiddleMazePath(Pos entry)
{
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);

	while (StackEmpty(&path))
	{
		Pos cur = StackTop(&path);
		Pos next;

		MiddleMaze[cur._row][cur._col] = 2;
		if (cur._col == 5)
		{

			if(pathsize == 0 || StackSize(&path) < pathsize)
			{
				pathsize = StackSize(&path);
			}
		}

		// 探测下一个去的位置
		// 上
		next = cur;
		next._row -= 1;
		if (CheckAccess(MiddleMaze, next))
		{
			StackPush(&path, next);
			continue;
		}

		// 下
		next = cur;
		next._row += 1;
		if (CheckAccess(MiddleMaze, next))
		{
			StackPush(&path, next);
			continue;
		}

		// 左
		next = cur;
		next._col -= 1;
		if (CheckAccess(MiddleMaze, next))
		{
			StackPush(&path, next);
			continue;
		}

		// 右
		next = cur;
		next._col += 1;
		if (CheckAccess(MiddleMaze, next))
		{
			StackPush(&path, next);
			continue;
		}

		// 回溯
		StackPop(&path);
	}
	if (pathsize != 0)
		return 1;
	return 0;
}

int CheckAccessUp(Pos cur, Pos next)
{
	if (next._row >= 0 && next._row < N && next._col >= 0 && next._col < N
		&& (DifficultMaze[next._row][next._col] == 1 || DifficultMaze[next._row][next._col] > DifficultMaze[cur._row][cur._col] + 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int GetDifficultMazePath(Pos entry)
{
	Stack path;
	StackInit(&path);
	StackPush(&path, entry);

	DifficultMaze[entry._row][entry._col] = 2;

	while (StackEmpty(&path))
	{
		Pos cur = StackTop(&path);
		Pos next;

		if (cur._col == 5)
		{

			if (pathsize == 0 || StackSize(&path) < pathsize)
			{
				pathsize = StackSize(&path);
			}
		}

		// 探测下一个去的位置
		// 上
		next = cur;
		next._row -= 1;
		if (CheckAccessUp(cur, next))
		{
			DifficultMaze[next._row][next._col] = DifficultMaze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		// 下
		next = cur;
		next._row += 1;
		if (CheckAccessUp(cur, next))
		{
			DifficultMaze[next._row][next._col] = DifficultMaze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		// 左
		next = cur;
		next._col -= 1;
		if (CheckAccessUp(cur, next))
		{
			DifficultMaze[next._row][next._col] = DifficultMaze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		// 右
		next = cur;
		next._col += 1;
		if (CheckAccessUp(cur, next))
		{
			DifficultMaze[next._row][next._col] = DifficultMaze[cur._row][cur._col] + 1;
			StackPush(&path, next);
			continue;
		}

		// 回溯
		StackPop(&path);
	}
	if (pathsize != 0)
		return 1;
	return 0;
}
void PrintMaze(int maze[N][N])
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

	PrintMaze(SimpleMaze);
	printf("是否有出口?:%d\n", GetSimpleMazePath(entry, exit));
	PrintMaze(SimpleMaze);

	PrintMaze(MiddleMaze);
	printf("是否有出口?:%d\n", GetMiddleMazePath(entry));
	printf("最短路径：%d\n", pathsize);
	PrintMaze(MiddleMaze);

	PrintMaze(DifficultMaze);
	printf("是否有出口?:%d\n", GetDifficultMazePath(entry));
	printf("最短路径：%d\n", pathsize);
	PrintMaze(DifficultMaze);
}
