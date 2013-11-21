#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;

struct node
{
  bool valid;
  int value;
  node(int m_value = 0, bool m_valid = true){value = m_value; valid = m_valid;}
  void value_set(int n)
  {
    value = n;
  }
  void del()
  {
    valid = false;
  }
  bool check()
  {
    return valid;
  }
  int value_get()
  {
    return value;
  }
};
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
  ~strategy()
  {
    delete [] a;
  }
  bool empty()
  {
    return (m_size == 0);
  }
  int l_idx_get(int idx)
  {
    int i, j;
    i = (idx + m_n) % m_n;
    j = 0;
    while (1)
    {
      if (a[i].check())
      {
        j++;
      }
      if (j == m_lk)
      {
        break;
      }
      i = (i - 1 + m_n) % m_n;
    }
    return i;
  }
  int r_idx_get(int idx)
  {
    int i, j;
    i = idx % m_n;
    j = 0;
    while (true)
    {
      if (a[i].check())
      {
        j++;
      }
      if (j == m_rm)
      {
        break;
      }
      i = (i + 1) % m_n;
    }
    return i;
  }
  void del(int idx)
  {
    a[idx].del();
    m_size--;
  }
  int value_get(int idx)
  {
    return a[idx].value_get();
  }
};

void solve(strategy& a)
{
  int l_idx = a.m_n - 1;
  int r_idx = 0;
  //stringstream ss;
  while (!a.empty())
  {
    l_idx = a.l_idx_get(l_idx);
    r_idx = a.r_idx_get(r_idx);
    if (l_idx == r_idx)
    {
      //ss << "  " << a.value_get(l_idx) << ",";
      printf("%3d", a.value_get(l_idx));
      a.del(l_idx);
    }
    else
    {
      //ss << "  " << a.value_get(l_idx) << "  " << a.value_get(r_idx) << ",";
      printf("%3d%3d", a.value_get(l_idx), a.value_get(r_idx));//占位符没注意，output里面的10前只有一个空格，还以为题的输出错了。。坑
      a.del(l_idx);
      a.del(r_idx);
    }
    if (!a.empty())
    {
      printf(",");
    }
  }
  //string s(ss.str());
  //s.erase(s.end() - 1);
  //cout << s << endl;
  printf("\n");
  return;
}
int main()
{
  int n, lk, rm;
  while (cin >> n >> lk >> rm)
  {
    if (!n && !lk && !rm)
    {
      //cout << endl;
      break;
    }
    
    strategy a(n, lk, rm);
    solve(a);
  }
  return 0;
}
