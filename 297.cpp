#include <iostream>
#include <string.h>

using namespace std;

const int max_len = 1024;
struct node 
{
  char m_c;
  struct node* child[4];
  node()
  {
    m_c = 0;
    for (int i = 0; i < 4; i++)
    {
      child[i] = NULL;
    }
  }
  void value_set(char c)
  {
    m_c = c;
    return ;
  }
  char value_get()
  {
    return m_c;
  }
};
struct node_pool
{
  node mem[1500];
  int idx;
  node_pool()
  {
    idx = 0;
  }
  node* alloc()
  {
    return &mem[idx++];
  }
};
struct counter
{
  bool a[max_len];
  counter()
  {
    memset(a, 0, sizeof(a));
  }
  void value_set(int idx)
  {
    a[idx] = true;
  }
  bool value_get(int idx)
  {
    return a[idx];
  }
  int sum() const
  {
    int s = 0;
    for (int i = 0; i < max_len; i++)
    {
      if (value_get(i)) s++;
    }
    return s;
  }
};

ostream& operator<<(ostream& o, const counter& cnt)
{
  o << cnt.sum();
  return o;
}
node* bfs(counter& cnt, const char* str, int& move, int a, int b)
{
  node* root = p.alloc();
  root->value_set(str[move++]);
  if (root->value_get() == 'p')
  {
    int mid = (a + b) >> 1;
    int m_l = (a + mid) >> 1;
    int m_r = (mid + b) >> 1;
    root->child[0] = bfs(cnt, str, move, a, m_l);
    root->child[1] = bfs(cnt, str, move, m_l+1, mid);
    root->child[2] = bfs(cnt, str, move, mid+1, m_r);
    root->child[3] = bfs(cnt, str, move, m_r+1, b);
  }
  else if (root->value_get() == 'f')
  {
    for (int i = a; i <= b; i++)
    {
      cnt.value_set(i);
    }
  }
  return root;
}
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
    node_pool p;
    bfs(cnt, s.c_str(), move = 0, 0, max_len - 1);
    cin >> s;
    bfs(cnt, s.c_str(), move = 0, 0, max_len - 1);
    cout << cnt << endl;
  }
  
  return 0;
}
