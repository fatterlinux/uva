#include <stdio.h>
#include <string.h>

int map[110][110];
int main()
{
  int m, n;
  while (scanf(%d %d%*c, &m, &n) && m)
  {
    memset(map, 0, sizeof(map));
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
        if ()
      }
    }
  }
}
