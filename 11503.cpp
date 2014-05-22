#include <iostream>
#include <map>
#include <string>

using namespace std;

typedef pair<string, <int, string> > elm;
class uf
{
  public:
  int find(string s)
  {
    string t = s;
    while (t != m[t].second) t = m[t].second;
    return m[t].first; 
  }
  connected(string a, string b)
  private:
  map<elm> m;
};
