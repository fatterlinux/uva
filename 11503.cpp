#include <iostream>
#include <map>
#include <string>

using namespace std;


class uf
{
  public:
  
  string find(string s)
  {
    if (id.find(s) == m.end())
    {
      id[s] = s;
      m[s] = 1;
    }
    string t = s;
    while (t != id[t]) t = id[t];
    return t 
  }
  
  int connected(string a, string b)
  {
    string x = find(a);
    string y = find(b);

    if (m[x] < m[y])
    {
      id[x] = y;
      m[y] += m[x];
      return m[y];
    }
    else
    {
      id[y] = x;
      m[x] += m[y];
      return m[x];
    }
    
  }
  private:
  map<string, string> id;
  map<string, int> m;

};

int main()
{
  int t;
  cin >> t;
  
  while (t--)
  {
    int a;
    cin >> a;
    uf u;
    while (a--)
    {
      string x, y;
      cin >> x >> y;
      cout << u.connected(x, y) <<endl;
    }
  }
  return 0;
}
