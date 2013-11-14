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
};
struct even_con
{
  node n[21];
  even_con()
  {
    
  }
}
char get_odd()//a, u, e, o, i
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
    while (idx <= len)
    {
      if (idx % 2)//odd
      {
        odd = odd + get_odd();
      }
      else //even
      {
        even = even + get_even();
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
