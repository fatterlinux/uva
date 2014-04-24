#include <iostream>
#include <queue>
#include <string>
#include <assert.h>
#include <stdio.h>

using namespace std;

static int run(queue<int>& q, queue<int>& other, int& time, int t, int n);
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
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
    int flag = -1;
    while (!(L.empty() && R.empty()))
    {
        if (flag == -1)
        {
          flag = run(L, R, time, t, n);
        }
        else
        {
          flag = run(R, L, time, t, n);
        }
    }
  }
  return 0;
}

static int run(queue<int>& q, queue<int>& other, int& time, int t, int n)
{
  int max_size = n;
  while (!q.empty() && q.front() <= time && max_size > 0)
  {
    cout << time + t << endl;
    q.pop();
    max_size--;
  }
  if (max_size != n)
  {
    time += t;
    return 1;
  }
  else if (!q.empty() && other.empty())
  {
    time = q.front();
    return -1;
  }
  else if (q.empty() && !other.empty())
  {
    time = t + other.empty();
    return 1;
  }
  else //说明本岸边没有车
  {
    if (other.front() <= t)
    {
      time += t;
      return 1;
    }
    else if (q.front() <= other.front())
    {
      time = q.front();
      return -1;
    }
    else if (q.front() > other.front())
    {
      time = t + other.front();
      return 1;
    }
    else
    {
      assert(0);
    }
    return 0;
  }
}
