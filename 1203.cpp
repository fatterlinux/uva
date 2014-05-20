#include <iostream>
#include <set>

class query
{
  public:
  query(_a, _b):a = _a, b = _b{ c = b;}
  ~query(){}
  bool operator< (const query& q)
  {
    return a < q.a;
  }
  int a, b, c;
};

int main()
{
  multiset<query> s;
  string s;
  int interval = 88888;
  while (cin >>s && s != "#")
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
      it->b -= interval;
      if (it->b == 0)
      {
        cout << it->a << endl;
        times--;
        it->b = it->c; 
      }
      if (it->b < interval2) interval2 = it->b;
    }
    interval = interval2;
  }
  return 0;
}
