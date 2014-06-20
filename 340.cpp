#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;
const int max_len = 1001;
const int range_len = 10;
int a[max_len], b[max_len];
int c[range_len], d[range_len], a_bak[range_len];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    int cnt(0);
    while (cin >> t && t)
    {
        printf("Game %d:\n", ++cnt);
        memset(c, 0, sizeof(c));
        for (int i = 0; i < t; i++)
        {
            scanf("%d", &a[i]);
            c[a[i]]++;
        }
        while (true)
        {
            memcpy(a_bak, c, sizeof(c));
            //for (int i = 0; i < range_len; i++)
            //{
            //    cout << a_bak[i] << " " ;
            //}
            //cout << endl;
            memset(d, 0, sizeof(d));
            for (int i = 0; i < t; i++)
            {
                scanf("%d", &b[i]);
                d[b[i]]++;
            }
            if(!b[0]) break;
            int s, w;
            s = w = 0;
            for (int i = 0; i < t; i++)
            {
                if (a[i] == b[i]) 
                {s++;
                a_bak[a[i]]--;
                d[a[i]]--;
                }
            }
            for (int i = 1; i < range_len; i++)
            {
                w += min(a_bak[i], d[i]);
            }
            printf("    (%d,%d)\n", s, w);
        }
    }
    return 0;
}
