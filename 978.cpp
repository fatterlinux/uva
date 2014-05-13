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
    multiset<int, greater<int> > sg, sl;
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
    //memset(battle, 0, sizeof(battle));
    while (!sg.empty() && !sl.empty())
    {
      for (int i = 0; i < fields; i++)
      {
        if (!sg.empty() && !sl.empty())
        {
          int a = *sg.begin();
          int b = *sl.begin();
          battle[i] = a - b;
          sg.erase(a);
          sl.erase(b);
        }
      }
      for (int i = 0; i < fields; i++)
      {
        if (battle[i] > 0) sg.insert(battle[i]);
        else if (battle[i] < 0) sl.insert(battle[i]);
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
      for (set<int>::iterator iter = sg.begin();iter != sg.end(); iter++)
      {
        cout << *iter <<endl;
      }
    }
    else if (!sl.empty())
    {
      assert(sg.empty());
      cout << "blue wins" <<endl;
      for (set<int>::iterator iter = sl.begin();iter != sl.end(); iter++)
      {
        cout << *iter << endl;
      }
    }
    else assert(0);
  }
}
