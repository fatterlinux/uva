#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct key_value
{
    string k;
    set<string> v;
};
const int max_size = 2000;
key_value dic[max_size];
int idx;

bool cmp_fun(const key_value& a, const key_value& b)
{
    return a.k < b.k;
}
int main()
{
    string a, b;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> a;
        getline(cin, b);
        int i;
        for (i = 0; i < idx; i++ )
        {
            if (dic[i].k == a)
            {
                dic[i].v.insert(b);
                break;
            }
        }
        if (i == idx)
        {
            idx++;
            dic[i].k = a;
            dic[i].v.insert(b);
        }
    }
    sort(dic, dic+idx, cmp_fun);
    for (int i = 0; i < idx; i++)
    {
        cout << dic[i].k << " " << dic[i].v.size() << endl;
    }
    return 0;
}