#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
  int test_case;
  while (cin >> test_case, test_case)
  {
    multiset<int> s;
    long long cost = 0;
    while (test_case--)
    {
      int t;
      cin >> t;
      while (t--)
      {
        int n;
        cin >> n;
        s.insert(n);
      }
      set<int>::iterator a = s.begin();
      set<int>::iterator b = --s.end(); //max_element也会超时
      cost += *b - *a;
      s.erase(a);
      s.erase(b);
    }
    cout << cost << endl;
  }
  return 0;
}
