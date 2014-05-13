#include <iostream>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <cstring>
#include <queue>
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
    //multiset<int, greater<int> > sg, sl;
    priority_queue<int> qg, qb;
    while (green--)
    {
      int t;
      scanf("%d", &t);
      //sg.insert(t);
      qg.push(t);
    }
    while (blue--)
    {
      int t;
      scanf("%d", &t);
      //sl.insert(t);
      qb.push(t);
    }
    //memset(battle, 0, sizeof(battle));
    //while (!sg.empty() && !sl.empty())
    while (!qg.empty() && !qb.empty())
    {
      int tmp = min(qg.size(), qb.size());
      tmp = min(tmp, fields);
      for (int i = 0; i < tmp; i++)
      {
        #if 0
        if (!sg.empty() && !sl.empty())
        {
          int a = *sg.begin();
          int b = *sl.begin();
          battle[i] = a - b;
          sg.erase(sg.begin());
          sl.erase(sl.begin());
        }
        #endif

        {
          int a = qg.top();
          int b = qb.top();
          battle[i] = a - b;
          qg.pop();
          qb.pop();
        }

      }
      for (int i = 0; i < tmp; i++)
      {
        #if 0
        if (battle[i] > 0) sg.insert(battle[i]);
        else if (battle[i] < 0) sl.insert(-battle[i]);
        #endif
        if (battle[i] >0) qg.push(battle[i]);
        else if (battle[i] < 0) qb.push(-battle[i]);
      }
      
    }

    if (qg.empty() && qb.empty())
    {
      cout << "green and blue died" <<endl;
    }
    else if (!qg.empty())
    {
      assert(qb.empty());
      cout << "green wins" << endl;
      while (!qg.empty())
      {
        cout << qg.top() <<endl;
        qg.pop();
      }
    }
    else if (!qb.empty())
    {
      assert(qg.empty());
      cout << "blue wins" <<endl;
      while (!qb.empty())
      {
        cout <<qb.top() <<endl;
        qb.pop();
      }
    }
    else assert(0);
  }
}
