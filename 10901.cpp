#include <iostream>
#include <queue>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <utility>
using namespace std;

int timer_table[10000];
typedef pair <int, int> elm;
static int run(queue<elm>& q, queue<elm>& other, int& time, int t, int n);
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int test_case;
    cin >> test_case;
    bool p_flag = false;
    while (test_case--)
    {
        if (p_flag)
        {
            cout << endl;
        }
        else
        {
            p_flag = true;
        }
        int n, t, m;
        memset(timer_table, 0, sizeof(timer_table));
        cin >> n >> t >> m;
        queue<elm> L, R;
        int h = 0;
        while (h < m)
        {
            string s;
            int time;
            cin >> time >> s;
            elm hh = make_pair(time, h);
            if (s == "left")
            {
                L.push(hh);
            }
            else 
            {
                R.push(hh);
            }
            h++;
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
        for (int i = 0; i < m; i++)
        {
            cout << timer_table[i] << endl;
        }
    }
    return 0;
}

static int run(queue<elm>& q, queue<elm>& other, int& time, int t, int n)
{
    int max_size = n;
    while (!q.empty() && q.front().first <= time && max_size > 0)
    {
        //cout << time + t << endl;
        timer_table[q.front().second] = time + t;
        q.pop();
        max_size--;
    }
    if (max_size != n)
    {
        time += t;
        return 1;
    }
    if (!other.empty() && other.front().first <= time)
    {
        time += t;
        return 1;
    }
    if (!q.empty() && other.empty())
    {
        time = q.front().first;
        return -1;
    }
    if (q.empty() && !other.empty())
    {
        time = t + other.front().first;
        return 1;
    }
    if (!q.empty() && !other.empty())
    {
        if (q.front() <= other.front())
        {
            time = q.front().first;
            return -1;
        }
        else
        {
            time = t + other.front().first;
            return 1;
        }
    }
}
