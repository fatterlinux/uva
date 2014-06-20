#include <iostream>
#include <cstdio>
using namespace std;


static int ans[100];
const int M = 6;
void combination(int a[], int pos, int n, int m)
{
    if (m == M)
    {
        for (int i = 0; i < M - 1; i++)
        {
            cout << ans[i] << " ";
        }
        cout << ans[M-1] << endl;
        return;
    }
    
    for (int i = pos; i < n; i++)
    {
        ans[m] = a[i];

        combination(a, i+1, n, m+1);
    }
    return;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int k;
    bool first(true);
    while (cin >> k && k)
    {
        if (first) first = false;
        else cout << endl;
        int* a = new int[k];
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        combination(a, 0, k, 0);
        delete [] a;
    }
    return 0;
}
