#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
  int test_case;
  cin >> test_case;
  bool first(true);
  while (test_case--)
  {
    if (first) first = false;
    else cout <<endl;
    string s;
    map<string, int> m;
    int cnt = 0;
    while (cin >> s)
    {
      if (s.[0] == '\n') break;
      m[s]++;
      cnt++;
    }
    for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++)
    {
      cout << iter->first << " ";
      printf("%.4lf\n", ((double)iter->second/cnt));
    }
  }
  return 0;
}
