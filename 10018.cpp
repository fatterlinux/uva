#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

long long reverse_num(long long n)
{
    stringstream ss;
    ss << n;
    string s;
    ss >> s;
    reverse(s.begin(), s.end());
    ss.clear();
    ss << s;
    ss >> n;
    return n;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y;
        cin >> x;
        y = reverse_num(x);
        long long z = x + y;
        long long z_reverse = reverse_num(z);
        int cnt = 1;
        while (z != z_reverse)
        {
            z = z + z_reverse;
            z_reverse = reverse_num(z);
            cnt++;
        }
        cout << cnt << " " << z << endl;
    }
    return 0;
}
