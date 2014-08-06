#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;
const int max_n = 21;
unsigned a[max_n];
unsigned dp(int n, int v)
{
    if (n == 0) return 0;
    unsigned res1 = 0;
    if (v >= a[n]) res1 = a[n] + dp(n - 1, v - a[n]);
    unsigned res2 = 0;
    res2 = dp(n - 1, v);
    return max(res1, res2);
}


int main()
{
    freopen("in.txt", "r", stdin);
    int v;
    while (cin >> v)
    {
        int n;
        cin >> n;
        memset(a, 0, sizeof(a));
        int i = 1;
        while (i <= n)
        {
           cin >> a[i];
           i++;
        }
        cout << "num:" << dp(n, v) << endl;
    }
    return 0;
}

