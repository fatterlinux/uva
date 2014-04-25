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
        int bank = -1;
        while (!(L.empty() && R.empty()))
        {
            int flag = bank;
            if (flag == -1)
            {
                flag = run(L, R, time, t, n);
            }
            else
            {
                flag = run(R, L, time, t, n);
            }
            if (flag == -1)
            {
                //nothing
            }
            else
            {
                bank = bank * (-1);
            }
        }
        cout << endl;
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
    if (!other.empty() && other.front() <= time)
    {
        time += t;
        return 1;
    }
    if (!q.empty() && other.empty())
    {
        time = q.front();
        return -1;
    }
    if (q.empty() && !other.empty())
    {
        time = t + other.front();
        return 1;
    }
    if (!q.empty() && !other.empty())
    {
        if (q.front() <= other.front())
        {
            time = q.front();
            return -1;
        }
        else
        {
            time = t + other.front();
            return 1;
        }
    }
}
