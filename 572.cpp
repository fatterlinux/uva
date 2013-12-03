#include <stdio.h>
#include <string.h>

int map[110][110];
void dfs(int i, int j);
int main()
{
  int m, n;
  while (scanf(%d %d%*c, &m, &n) && m)
  {
    memset(map, 0, sizeof(map));
    int cnt = 0;
    for (int i = 1; i <=m; i++)
    {
      char str[110];
      gets(str);
      for (int j = 1; j <= n; j++)
      {
        if (str[j - 1] == '@')
        {
          map[i][j] = 1;
        }
      }
    }
    
    for (int i = 1; i <=m; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (map[i][j])
        {
          dfs(i, j);
          cnt++;
        }
      }
    }
  }
  return 0;
}

const int dir[][2] = {()};
void dfs(int i, int j)
{
  map[i][j] = 0;
  if (map[])
}
