#include <iostream>
#include <set>
#include <stdio.h>

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
    
    scanf("%d", &t);
    s.insert(t);
    }
    int cnt = 0;
    while (m--)
    {
      int t ;
      scanf("%d", &t);
      if (s.count(t))
      {
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
