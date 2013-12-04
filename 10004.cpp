#include <iostream>
#include <queue>
#include <string.h>

using namespace std;
enum color_enum
{
  red = 0,
  black,
};
const int max_len = 210;
bool visit[max_len];
bool color_visit[max_len];
int edge[max_len][max_len];
color_enm color[max_len];
void init()
{
  memset(visit, 0, sizeof(visit));
  memset(color_visit, 0, sizeof(color_visit));
  memset(edge, 0, sizeof(edge));
  memset(color, 0, sizeof(color));
}
void color_bfs(int idx, int n)
{
  queue<int> q;
  color_visit[idx] = true;
  color[idx] = red;
  q.push(idx);
  while (!q.empty())
  {
    int t = q.front();
    q.pop();
    for (int i = 0; i < max_len; i++)
    {
      if (edge[t][i] && !color_visit[i])
      {
        color_visit[i] = true;
        color[i] = ((color[t] == red) ? black : red);
        q.push(i);
      }
    }
  }
}
bool dfs(int idx)
{
  visit[idx] = true;
  for (int i = 0; i < max_len; i++)
  {
    if (!visit[i])
    {
      visit[i] = true;
      if (color[i] == color[idx]) return false;
      else
      {
        if (!dfs(i)) return false;
      }
    }
  }
  return true;
}
int main()
{
  int n;
  while (cin >> n, n)
  {
    init();
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
      int a, b;
      cin >> a >> b;
      edge[a][b] = edge[b][a] = 1;
    }
    color_bfs(0, n);
    bool flag(true);
    for (int i = 0; i < n; i++)
    {
      if (!visit[i])
      {
        if (!dfs(i))
        {
          flag = false;
          break;
        }
      }
    }
    cout << (flag ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
  }
}
