#include <iostream>
#include <stdio.h>
#include <bitset>

//const int time_range = 1000001;
const int time_range = 1000001;
using namespace std;

bitset<time_range> b;

int
main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;
    while (cin >> n >> m && !(n == 0 && m == 0))
    {
        b.reset();
        bool found_flag(false);
        while (n--)
        {
            int t_start, t_end;
            cin >> t_start >> t_end;
            if (found_flag) continue;

            for (int i = t_start; i < t_end; i++)
            {
                if (b.test(i))
                {
                    //cout << "conflict " << i << endl;
                    found_flag = true;
                }
                else
                {
                    b.set(i);
                    
                }
                if (found_flag) break;
            }
        }
        while (m--)
        {
            int t_start, t_end, interval;
            cin >> t_start >> t_end >> interval;
            if (found_flag) continue;
            for (int i = 0; t_start + i*interval < time_range; i++)
            {
                int s = t_start + i*interval;
                int e = t_end + i*interval;
                for (int j = s; j < e; j++)
                {
                    if (b.test(j))
                    {
                        found_flag = true;
                        break;
                    }
                    else
                    {
                        b.set(j);
                    }
                }
                if (found_flag) break;
            }
        }
        if (found_flag) cout << "CONFLICT" << endl;
        else cout << "NO CONFLICT" << endl;
    }
    return 0;
}
