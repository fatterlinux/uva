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
            for (int i = t_start; i < t_end + 1; i++)
            {
                if (b.test(i) && i != t_start && i != t_end)
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
            int t_range = t_end - t_start;
            while (t_start < time_range)
            {
                int i = t_start;
                int range = t_start + t_range;
                //cout << "t_start: " << t_start << " t_end: " << t_end << endl;
                while (t_start <= range && t_start < time_range)
                {
                    //cout << t_start << endl;
                    if (b.test(t_start) && i != t_start && i != range)
                    {
                        found_flag = true;
                        //cout << "interval conflict " << t_start << endl;
                    }
                    else
                    {
                        b.set(t_start);
                    }
                    if (found_flag) break;
                    t_start++;
                    i++;
                }
                if (found_flag) break;
                t_start += interval;
            }
        }
        if (found_flag) cout << "CONFLICT" << endl;
        else cout << "NO CONFLICT" << endl;
    }
    return 0;
}
