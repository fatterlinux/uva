#include <iostream>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <cstring>
using namespace std;

static int battle[100001];
int main()
{
  int test_case;
  cin >> test_case;
  bool first(true);
  while (test_case--)
  {
    if (first) first = false;
    else cout <<endl;
    int fields, green, blue;
    cin >> fields >> green >> blue;
    set<int> sg, sl;
    while (green--)
    {
      int t;
      cin >> t;
      sg.insert(t);
    }
    while (blue--)
    {
      int t;
      cin >>t;
      sl.insert(t);
    }
    memset(battle, 0, sizeof(battle));
    while (!sg.empty() && !sl.empty())
    {
      for (int i = 0; i < fields; i++)
      {
        if (battle[i] == 0 && !sg.empty() && !sl.empty())
        {
          int a = *sg.rbegin();
          int b = *sl.rbegin();
          battle[i] = a - b;
          sg.erase(a);
          sl.erase(b);
        }
        else if (battle[i] <0 && !sg.empty())
        {
          int a = *sg.rbegin();
          battle[i] += a;
          sg.erase(a);
        }
        else if (!sl.empty())
        {
          int b = *sl.rbegin();
          battle[i] -= b;
          sl.erase(b);
        }
      }
      
    }
    for (int i = 0; i < fields; i++)
    {
      if (battle[i] >0)
      {
        sg.insert(battle[i]);
      }
      else if (battle[i] <0)
      {
        sl.insert(-battle[i]);
      }
    }
    if (sg.empty() && sl.empty())
    {
      cout << "green and blue died" <<endl;
    }
    else if (!sg.empty())
    {
      assert(sl.empty());
      cout << "green wins" << endl;
      for (set<int>::reverse_iterator iter = sg.rbegin();iter != sg.rend(); iter++)
      {
        cout << *iter <<endl;
      }
    }
    else if (!sl.empty())
    {
      assert(sg.empty());
      cout << "blue wins" <<endl;
      for (set<int>::reverse_iterator iter = sl.rbegin();iter != sl.rend(); iter++)
      {
        cout << *iter << endl;
      }
    }
    else assert(0);
  }
}
