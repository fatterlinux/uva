#include <iostream>
#include <string>

using namespace std;

struct node
{
  char m_c;
  int m_times;
  node()
  {
    m_c = 'A';
    m_times = 0;
  }
  node& operator=(const node& i)
  {
    m_c = i.m_c;
    m_times = i.times;
    return *this;
  }
  void set_vowel_value(char c)
  {
    m_c = c;
    m_times = 20;
  }
  void set_con_value(char c)
  {
    m_c = c;
    m_times = 4;
  }
};
struct odd_vowel
{
  node n[5];
  static char map[5] = {'A', 'U', 'E', 'O', 'I'};
  odd_vowel()
  {
    for (int i = 0; i < 5; i++)
    {
      n[i].set_vowel_value(map[i]);
    }
  }
  char get_char()
  {
    for (int i = 0; i < 5; i++)
    {
      if (n[i].times)
      {
        n[i].times--;
        return n[i].c;
      }
    }
    assert(0);
    return 'x';
  }
};
struct even_con
{
  node n[21];
  static char map[21] = {'J', 'S', 'B', 'K', 'T', 'C', 'L', 'D', 'M', 'V', 'N', 'W', 'F', 'X', 'G', 'P', 'Y', 'H', 'Q', 'Z', 'R'};
  even_con()
  {
    for (int i = 0; i < 21; i++)
    {
      n[i].set_con_value(map[i]);
    }
  }
  char get_char()
  {
    for (int i = 0; i < 21; i++)
    {
      if (n[i].times)
      {
        n[i].times--;
        return n[i].c;
      }
    }
    assert(0);
    return 'x';
  }
}
char get_odd(odd_vowel& o)//a, u, e, o, i
{
  for (int i = 0; i < )
}
int main()
{
  int test_case;
  cin >>test_case;
  while (test_case--)
  {
    int len;
    cin >> len;
    int idx = 1;
    string odd, even;
    odd_vowel o;
    even_con e;
    while (idx <= len)
    {
      if (idx % 2)//odd
      {
        odd = odd + o.get_char();
      }
      else //even
      {
        even = even + e.get_char();
      }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    for (int i = 1; i <= len; i++)
    
    {
      if (i % 2)
      {
        cout << odd[i-1];
      }
      else
      {
        cout << even[i-1];
      }
    }
    cout <<endl;
  }
}
