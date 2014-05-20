#include <iostream>
#include <queue>
#include <stack>
#include <stdio.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    while (cin >> n)
    {
        queue<int> q;
        priority_queue<int> pq;
        stack<int> s;
        bool is_q, is_pq, is_s;
        is_q = is_pq = is_s = true;

        while (n--)
        {
            int a, b;
            cin >> a >> b;
            if (a == 1)
            {
                q.push(b);
                pq.push(b);
                s.push(b);
            }
            else
            {
                if (q.empty() || b != q.front()) is_q = false;
                if (pq.empty() || b != pq.top()) is_pq = false;
                if (s.empty() || b != s.top()) is_s = false;
                if (!q.empty())q.pop();
                if (!pq.empty())pq.pop();
                if (!s.empty())s.pop();
            }
        }
        int cnt = 0;
        if (is_q) cnt++;
        if (is_pq) cnt++;
        if (is_s) cnt++;
        if (cnt == 0) cout << "impossible";
        else if (cnt > 1) cout << "not sure";
        else
        {
            if (is_q) cout << "queue";
            else if (is_s) cout << "stack";
            else cout << "priority queue";
        }
        cout << endl;
    }
    return 0;
}

