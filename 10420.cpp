#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <string>

using namespace std;
struct dict
{
    string k;
    set<string> v;
}; 
bool cmp_f(const dict& a, const dict& b)
{
    return a.k< b.k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t ;
    cin >> t;
    dict d[1000];
    int cnt(0);
    while (t--)
    {
        string a, b;
        cin >> a;
        getline(cin, b);
        b.erase(0, b.find_first_not_of(" "));
        int i;
        for (i = 0; i < cnt; i++)
        {
            if (d[i].k == a)
            {
                break;
            }
        }
        if (i == cnt)
        {
            d[i].k = a;
            d[i].v.insert(b);
            cnt++;
        }
        else
        {
            d[i].v.insert(b);
        }
    }
    sort(d, d + cnt, cmp_f);
    for (int i = 0; i < cnt; i++)
    {
        cout << d[i].k << " " << d[i].v.size() << endl;
    }
    return 0;
}
