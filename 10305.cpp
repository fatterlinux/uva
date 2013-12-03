#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>

using namespace std;

const int max_len = 110;
int edge[max_len][max_len];
int res[max_len];
int indegree[max_len];

void init()
{
  memset(edge, 0, sizeof(edge));
  memset(res, 0, sizeof(res));
  memset(indegree, 0, sizeof(indegree));
}

void topologic(int n)
{
  
}
int main()
{
  int n, m;
  while (cin >> n >> m)
  {
    if (!n && !m) break;
    init();
    for (int i = 0; i < m; i++)
    {
      int a, b;
      cin >> a >> b;
      edge[a][b] = 1;
      indegree[b] ++;
    }
    topologic(n);
  }
  return 0;
}
