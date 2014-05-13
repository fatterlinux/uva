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
  string s;
  getline(cin, s);
  getline(cin, s);
  while (test_case--)
  {
    if (first) first = false;
    else cout <<endl;
    map<string, int> m;
    int cnt = 0;
    while (getline(cin, s))
    {
      if (s.[0] == '\n') break;
      m[s]++;
      cnt++;
    }
    for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++)
    {
      cout << iter->first << " ";
      printf("%.4lf\n", ((double)iter->second/cnt * 100));
    }
  }
  return 0;
}
