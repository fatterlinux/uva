#include <iostream>
#include <string>
#include <algorithm>
#include <assert.h>

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
    m_times = i.m_times;
    return *this;
  }
  void set_vowel_value(char c)
  {
    m_c = c;
    m_times = 21;
  }
  void set_con_value(char c)
  {
    m_c = c;
    m_times = 5;
  }
};
struct odd_vowel
{
  node n[5];
  static char map[5];
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
      if (n[i].m_times)
      {
        n[i].m_times--;
        return n[i].m_c;
      }
    }
    assert(0);
    return 'x';
  }
};
char odd_vowel::map[5] = {'A', 'U', 'E', 'O', 'I'};
struct even_con
{
  node n[21];
  static char map[21];
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
      if (n[i].m_times)
      {
        n[i].m_times--;
        return n[i].m_c;
      }
    }
    assert(0);
    return 'x';
  }
};
char even_con::map[21] = {'J', 'S', 'B', 'K', 'T', 'C', 'L', 'D', 'M', 'V', 'N', 'W', 'F', 'X', 'G', 'P', 'Y', 'H', 'Q', 'Z', 'R'};

int main()
{
  int test_case;
  cin >>test_case;
  int test_idx = 1;
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
      idx++;
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    int odd_index = 0;
    int even_index = 0;
    cout << "Case " << test_idx << ": ";
    test_idx++;
    for (int i = 1; i <= len; i++)
    
    {
      if (i % 2)
      {
        cout << odd[odd_index++];
      }
      else
      {
        cout << even[even_index++];
      }
    }
    cout <<endl;
  }
}
