#include <stdio.h>
#include <string.h>
#include <queue>

int map[110][110];
void dfs(int i, int j);
void bfs(int i, int j);
int main()
{
  int m, n;
  while (scanf("%d %d%*c", &m, &n) && m)
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
          //dfs(i, j);
          bfs(i, j);
          cnt++;
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}

const int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}; 
void dfs(int i, int j)
{
  map[i][j] = 0;
  for (int k = 0; k < 8; k++)
  {
    if (map[i + dir[k][0]][j + dir[k][1]]) dfs(i + dir[k][0], j + dir[k][1]);
  }
}
struct node
{
  int i, j;
};
void bfs(int i, int j)
{
  std::queue<node> Q;
  node temp;
  temp.i = i;
  temp.j = j;
  map[i][j] = 0;
  Q.push(temp);
  
  while (!Q.empty())
  {
    node t = Q.front();
    Q.pop();
    for (int k = 0; k < 8; k++)
    {
      if (map[t.i + dir[k][0]][t.j + dir[k][1]])
      {
        map[t.i + dir[k][0]][t.j + dir[k][1]] = 0;
        node tt;
        tt.i = t.i + dir[k][0];
        tt.j = t.j + dir[k][1];
        Q.push(tt);
      }
    }
  }
}
