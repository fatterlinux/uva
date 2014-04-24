#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
  int test_case;
  cin >> test_case;
  while (test_case--)
  {
    int n, t, m;
    cin >> n >> t >> m;
    queue<int> L, R;
    while (m--)
    {
      string s;
      int time;
      cin >> time >> s;
      if (s == "left")
      {
        L.push(time);
      }
      else 
      {
        R.push(time);
      }
    }
    int time = 0;
    while (!(L.empty() && R.empty()))
    {
      int max_size = n;
      while (!L.empty() && L.front() <= time && max_size > 0)
      {
        cout << time + t << endl;
        L.pop();
        max_size--;
      }
      if (max_size == n && R.front() > time)
      {
        time = R.front();
      }
      time += t;
      max_size = n;
      while (!R.empty() && R.front() <= time && max_size > 0)
      {
        cout << time + t << endl;
        R.pop();
        max_size--;
      }
      if (max_size == n && L.front > time)
      {
        time = L.front();
      }
      time += t;
    }
  }
  return 0;
}
