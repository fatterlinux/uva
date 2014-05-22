#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

typedef pair<string, <int, string> > elm;
class uf
{
  public:
  uf():cnt(0){}
  int find(string s)
  {
    if (m.find(s) == m.end()) return 0;
    string t = s;
    while (t != m[t].second) t = m[t].second;
    return m[t].first; 
  }
  
  void connected(string a, string b)
  {
    int x = find(a);
    int y = find(b);
    if (x == 0 && y == 0)
    {
      elm ea(a, (cnt, a));
      elm eb(b, (cnt, b));
      ss[a] = 1;
      ss[b] = 1;
    }
  }
  private:
  map<elm> m;
  map<string, int> ss;
  int cnt;
  void __connected(sting a, string b)
  {
    
  }
};
