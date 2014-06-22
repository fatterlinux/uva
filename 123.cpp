#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    set<string> ignore;
    string t;
    while (cin >> t && t != "::")
    {
        ignore.insert(t);
    }

    multimap <string, string> m;
    while (getline(cin , t))
    {
        for (int i = 0; i < t.size(); i++)
        {
            if (!isalpha(t[i])) continue;
            t[i] = tolower(t[i]);
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (!isalpha(t[i])) continue;
            int j(i);
            string tt;
            while (j < t.size() && isalpha(t[j]))
            {
                tt += t[j];
                j++;
            }
            if (!ignore.count(tt))
            {
                string ttt(t);
                for (int k = 0; k < tt.size(); k++)
                {
                    tt[k] = toupper(tt[k]);
                }
                ttt.replace(i, tt.size(), tt);
                m.insert(make_pair(tt, ttt));
            }
            i = j;
        }
    }

    for (map<string, string>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << it->second << endl;
    }
    return 0;
}
