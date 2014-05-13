#include <iostream>
#include <set>

using namespace std;

int main()
{
  int n, m;
  while (cin >> n >> m, m || n)
  {
    set<int> s;
    while (n--)
    {
    int t;
    
    cin >> t;
    s.insert(t);
    }
    int cnt = 0;
    while (m--)
    {
      int t ;
      cin >>t;
      if (s.find(t) != s.end())
      {
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
