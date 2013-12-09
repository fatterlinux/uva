#include <iostream>
#include <stdio.h>

using namespace std;
const int max_len = 210;
bool visit[max_len];
int edge[max_len][max_len];
int degree[max_len];
void reset()
{
  memset(visit, 0, sizeof(visit));
  memset(edge, 0, sizeof(edge));
  memset(degree, 0, sizeof(degree));
}
void dfs(int idx, int n)
{
  visit[idx] = true;
  for (int i = 0; i < n; i++)
  {
    if (!visit[idx] && edge[idx][i])
    {
      dfs(i, n);
    }
  }
}
int main()
{
  int n, m;
  while (cin >> n >> m)
  {
    int a, b;
    reset();
    for (int i = 0; i < m; i++)
    {
      cin >> a >> b;
      edge[a][b] = edge[b][a] = 1;
      degree[a]++;
      degree[b]++;
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
      if (degree[i] % 2)
      {
        flag = false;
        break;
      }
    }
    if (!flag)
    {
      cout << "Not Possible" << endl;
      continue;
    }
    dfs(0, n);
    for (int i = 0; i < n; i++)
    {
      if (!visit[i])
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      cout << "Possible" << endl;
    }
    else
    {
      cout << "Not Possible" << endl;
    }
  }
  return 0;
}
