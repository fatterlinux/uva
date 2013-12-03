#include <iostream>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

struct node
{
  int x, y;
  bool operaotr==(const node& a) const
  {
    return (x==a.x && y==b.y);
  }
};
void bfs(const node& a, const node& b);
int main()
{
  string a_str, b_str;
  while (cin >> a_str >> b_str)
  {
    node a, b;
    const char* a_char = a_str.c_str();
    const char* b_char = b_str.c_str();
    a.x = a_char[0];
    a.y = a_char[1];
    b.x = b_char[0];
    b.y = b_char[1];
    bfs(a, b);
    printf("To get from %s to %s takes %d knight moves.\n", a_char, b_char, mark[b.x][b.y]);
  }
  return 0;
}
static int dir
void bfs(const node& a, const node& b)
{}
