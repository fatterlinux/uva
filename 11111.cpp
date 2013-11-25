#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <assert.h>

using namespace std;

struct node
{
    int m_a;
    int m_b;
    node(int a): m_a(a)
    {
        m_b = abs(m_a);
    }
};
int main(void)
{
    string s;
    while (getline(cin, s))
    {
        stringstream ss(s);
        int num;
        queue<int> q;
        while (ss >> num)
        {
            q.push_back(num); 
        }
        if (q.size() % 2)
        {
            cout << ":-( Try again." << endl;
            continue;
        }
        stack<node> sc;
        stack<int> checker;
        bool err_flag(true);
        for (int i = 0; i < q.size(); i++)
        {
            if (q[i] < 0)
            {
                sc.push(node(q[i]));
                checker(q[i]);
            }
            else if (q[i] > 0)
            {
                if (checker.empty())
                {
                    err_flag = false;
                    break;
                }
                if (checker.top() != q[i])
                {
                    err_flag = false;
                    break;
                }
                else
                {
                    checker.pop();
                }
                if (sc.empty())
                {
                    err_flag = false;
                    break;
                }
                if (q[i] == abs(sc.top().m_a))
                {
                    sc.pop();
                    if (!sc.empty())
                    {
                        node pre = sc.top();
                        sc.pop();
                        pre.m_b -= q[i];
                        if (pre.m_b <= 0)
                        {
                            err_flag = false;
                            break;
                        }
                        else
                        {
                            sc.push(pre);
                        }
                    }
                    else if (i != (q.size() - 1))
                    {
                        err_flag = false;
                        break;
                    }
                    else/*last elm end OK! */
                    {}
                }
                else/*q[i] != abs(sc.top())*/
                {
                   node t = sc.top();
                   sc.pop();
                   t.m_b -= q[i];
                   if (t.m_b <= 0)
                   {
                        err_flag = false;
                        break;
                   }
                   sc.push(t);
                }

            }
            else
            {
                assert(0);
            }
        }
        if (!err_flag || !sc.empty())
        {
            cout << ":-( Try again." << endl;
        }
        else
        {
            cout << ":-) Matrioshka!" << endl;
        }
    }
}
