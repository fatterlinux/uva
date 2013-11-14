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
  void set_value(char c, int times)
  {
    m_c = c;
    m_times = times;
  }
};
struct odd_vowel
{
  node n[5];
  odd_vowel()
  {
    n[0].set_value('A', 4);
    n[1].set_value('U', 4);
    n[2].set_value('E', 4);
    n[3].set_value('O', 4);
    n[4].set_value('I', 4);
  }
};
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
