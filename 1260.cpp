#include <iostream>
#include <cstdio>

using namespace std;

const int max_n = 1000;
static int a[max_n];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int sum = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[j] <= a[i]) sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
