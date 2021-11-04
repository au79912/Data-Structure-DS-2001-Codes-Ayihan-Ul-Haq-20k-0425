#include <iostream>

using namespace std;

//rat in a maze solution by backtracking
void rat_in_a_maze(int maze[][10], int n, int m, int x, int y)
{
	if (x == n - 1 && y == m - 1)
	{
		cout << "Found the exit" << endl;
		return;
	}
	if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] == 0)
	{
		cout << "No exit" << endl;
		return;
	}
	maze[x][y] = 0;
	rat_in_a_maze(maze, n, m, x + 1, y);
	rat_in_a_maze(maze, n, m, x - 1, y);
	rat_in_a_maze(maze, n, m, x, y + 1);
	rat_in_a_maze(maze, n, m, x, y - 1);
	maze[x][y] = 1;
}

//main function
int main()
{
	int maze[][10] = 
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
		{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 1, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 1, 1, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	rat_in_a_maze(maze, 10, 10, 0, 0);
	return 0;
}

