#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
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
    //freopen("test.in", "r", stdin);
    string s;
    while (getline(cin, s))
    {
        stringstream ss(s);
        int num;
        vector<int> q;
        while (ss >> num)
        {
            q.push_back(num); 
        }

        if ((q.size() == 0) ||q.size() % 2)
        {
            cout << ":-( Try again." << endl;
            continue;
        }
        stack<node> sc;
        bool err_flag(true);
        for (int i = 0; i < q.size(); i++)
        {
            if (q[i] < 0)
            {
                sc.push(node(q[i]));
            }
            else if (q[i] > 0)
            {
                if (sc.empty() || (abs(sc.top().m_a) != q[i]))//没有abs
                {
                    //assert (0);
                    err_flag = false;
                    break;
                }

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
