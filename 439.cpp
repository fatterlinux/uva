#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>

using namespace std;

struct node
{
  int x, y;
  bool operator==(const node& a) const
  {
    return (x==a.x && y==a.y);
  }
  bool check() const 
  {
    return (x >= 1 && x <= 8 && y >= 1 && y <=8);
  }
};
const int max_len = 10;
bool visit[max_len][max_len];
int mark[max_len][max_len];
void init()
{
  memset(visit, 0, sizeof(visit));
  memset(mark, 0, sizeof(mark));
}
void bfs(const node& a, const node& b);
int main()
{
  string a_str, b_str;
  while (cin >> a_str >> b_str)
  {
    node a, b;
    const char* a_char = a_str.c_str();
    const char* b_char = b_str.c_str();
    a.x = a_char[0] - 'a' + 1;
    a.y = a_char[1] - '0';
    b.x = b_char[0] - 'a' + 1;
    b.y = b_char[1] - '0';
    init();
    bfs(a, b);
    printf("To get from %s to %s takes %d knight moves.\n", a_char, b_char, mark[b.x][b.y]);
  }
  return 0;
}
void visit_set(const node& a)
{
  visit[a.x][a.y] = true;
}
bool visit_get(const node& a)
{
  return visit[a.x][a.y];
}
const int dir[][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2},
                        {-1, -2}, {-2, -1}};
void bfs(const node& a, const node& b)
{
  if (a == b) return;
  queue<node> q;
  visit_set(a);
  q.push(a);
  
  while (!q.empty())
  {
    node t = q.front();
    q.pop();
    for (int i = 0; i < 8; i++)
    {
      node next;
      next.x = t.x + dir[i][0];
      next.y = t.y + dir[i][1];
      if (!next.check()) continue;
      if (visit_get(next)) continue;
      visit_set(next);
      mark[next.x][next.y] = mark[t.x][t.y] + 1;
      if (next == b) return;
      q.push(next);
    }
  }
  return;
}
