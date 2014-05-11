#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
const int N = (1 << 15);
int corner[N],sum[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < (1 << n); i++)
        {
            cin >> corner[i];
        }

        for (int i = 0; i < (1 << n); i++)
        {
            sum[i] = 0;
            for (int j = 0; j < n; j++)
            {
                sum[i] += corner[i^(1<<j)];
            }
        }
        int max_sum = 0;
        for (int i = 0; i < (1 << n); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (sum[i] + sum[i^(1<<j)] > max_sum)
                {
                    max_sum = sum[i] + sum[i^(1<<j)];
                }
            }
        }
        cout << max_sum << endl;
    }
    return 0;
}

