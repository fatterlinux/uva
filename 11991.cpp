#include <iostream>
#include <vector>

using namespace std;


static vector<int> a[1000001];
int main()
{
  int n, m;
  while (cin >> n && cin >> m)
  {
    for(int i = 0; i < 1000001;i++)
    {
      a[i].clear();
    }
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
      if (a[aa].size() <b)
      {
        cout << 0;
      }
      else
      {
        cout << a[aa][b-1];
      }
      cout <<endl;
    }
  }
  return 0;
}
