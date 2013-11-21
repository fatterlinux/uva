#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct strategy
{
  int m_n, m_lk, m_rm;
  int m_size;
  node* a;
  strategy(int n, int lk, int rm):m_n(n), m_lk(lk), m_rm(rm)
  {
    m_size = m_n;
    a = new node[m_n];
    for (int i = 0; i < m_n; i++)
    {
      a[i].value_set(m_n - i);
    }
  }
};
int main()
{
  int n, lk, rm;
  while (cin >> n >> lk >> rm)
  {
    if (!n && !lk && !rm)
    {
      break;
    }
    strategy a(n, lk, rm);
    solve(a);
  }
  return 0;
}
