#include <iostream>
#include <set>
#include <string>

using namespace std;

class query
{
  public:
  query(int _a, int _b):a(_a), b(_b){ c = b;}
  ~query(){}

  int a, b, c;
};

  bool operator< (const query& a, const query& q)
  { 
    return a.a < q.a;
  }
int main()
{
  multiset<query> s;
  string ss;
  int interval = 88888;
  while (cin >>ss && ss != "#")
  {
    int a, b;
    cin >> a >> b;
    query q(a, b);
    s.insert(q);
    if (interval > b) interval = b;
  }
  int times;
  cin >> times;
  int interval2 = interval;
  while (times)
  {
    set<query>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
    {
      query a = *it;
      a.b -= interval;
      if (a.b == 0)
      {
        cout << a.a << endl;
        times--;
        a.b = a.c; 
      }
      s.erase(it);
      s.insert(a);
      if (a.b < interval2) interval2 = a.b;
    }
    interval = interval2;
  }
  return 0;
}
