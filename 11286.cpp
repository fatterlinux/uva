#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  while (cin >> n, n)
  {
    map< <vector<int>, int > m;
    int popularity = 0;
    while (n--)
    {
      vector<int> v(5);
      for (int i = 0; i < 5; i++)
      {
        cin >> v(i);
      }
      sort(v.begin(), v.end());
      m[v]++;
      popularity = max(popularity, m[v]);
    }
    int total = 0;
    for (map< vector<int>, int >::iterator iter = m.begin(); iter != m.end(); iter++)
    {
      if (iter->second == popularity) total++;
    }
    cout << total << endl;
  }
}
