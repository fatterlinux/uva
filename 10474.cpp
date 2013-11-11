#include <iostream>
#include <vector>

using namespace std;
int idx;
int main()
{
    int a, b;
    
    while (cin >> a >> b)
    {
        if (!a && !b)
        {
            break;
        }
        idx++;
        vector<int> v;
        while (a--)
        {
            v.insert(a);
        }
        sort(v.begin, v.end);
        cout << "CASE# " << idx << ":" << endl;
        while (b--)
        {
            int t;
            cin >> t;
            int i;
            for (i = 0; i < v.size(); i++)
            {
                if (v[i] == t)
                {
                    cout << t << " found at " << i << endl;
                    break;
                }
            }
            if (i == v.size())
            {
                cout << t << " not found" << endl;
            }
        }
    }
    return 0;
}