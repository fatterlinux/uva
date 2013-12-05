#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void init();
void input();
void solve();
void output();

int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    init();
    input();
    solve();
    output();
  }
  return 0;
}
const int max_row = 32;
const int max_col = 82;
char maze[max_row][max_col];
bool visit[max_row][max_col];
void init()
{
  memset(maze, 0, sizeof(maze));
  memset(visit, 0, sizeof(visit));
}
void input(int& cnt)
{
  while (gets(maze[cnt]))
  {
    if (maze[cnt][0] == '_')
    {
      break;
    }
    cnt++;
  }
}
const int dir[8][2] = {{-1, 0}, {0, -1},
                        {0, 1},{1, 0},{-1, -1},{-1, 1},{1, 1},{1, -1}};
void dfs(int m, int n, int cnt)
{
  visit[m][n] = true;
  if (maze[m][n] == 'X') return;
  if (maze[m][n] == ' ' || maze[m][n] == '*') maze[m][n] = '#';
  for (int i = 0; i < 8; i++)
  {
    int x = m + dir[i][0];
    int y = n + dir[i][1];
    if (!visit[x][y]) dfs(x, y);
  }
}
void solve(int cnt)
{
  for (int i = 0; i < cnt; i++)
  {
    for (int j = 0; j < strlen(maze[i]); j++)
    {
      if (maze[i][j] == '*' && visit[i][j])
      {
        dfs(i, j, cnt);
      }
    }
  }
}
