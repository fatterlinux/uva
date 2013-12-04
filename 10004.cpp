#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

init()
{}
int main()
{
  int n;
  while (cin >> n, n)
  {
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
