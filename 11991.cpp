#include <iostream>
#include <vector>
#include <map>

using namespace std;


//static vector<int> a[1000001];
static map<int , vector<int> > a;
int main()
{
  int n, m;
  while (cin >> n && cin >> m)
  {
    a.clear();
    int i = 1;
    while (i <= n)
    {
      int t;
      cin >> t;
      a[t].push_back(i);
      i++;
    }
    while (m--)
    {
      int aa, b;
      cin >> aa >> b;
      if (!a.count(b) || a[b].size() <aa)
      {
        cout << 0;
      }
      else
      {
        cout << a[b][aa-1];
      }
      cout <<endl;
    }
  }
  return 0;
}
