#include <iostream>
#include <set>
using namespace std;

static int battle[100001];
int main()
{
  int test_case;
  cin >> test_case;
  while (test_case--)
  {
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
        if (battle[i] == 0)
        {
          int a = *sg.rbegin();
          int b = *sl.rbegin();
          battle[i] = a - b;
          sg.erase(a);
          sl.erase(b);
        }
        else if (battle[i] <0)
        {
          int a = *sg.rbegin();
          battle[i] += a;
          sg.erase(a);
        }
        else
        {
          int b = *sl.rbegin();
          battle[i] -= b;
          sl.erase(b);
        }
      }
    }
  }
}
