#include <iostream>

using namespace std;

int main()
{
  int test_case;
  cin >> test_case;
  while (test_case--)
  {
    string s;
    cin >> s;
    int move;
    counter cnt;
    bfs(cnt, move = 0, 0, max_len - 1);
    cin >> s;
    bfs(cnt, move = 0, 0, max_len - 1);
  }
}
