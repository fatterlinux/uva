#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    int cnt = 0;
    while (cin >> t && t)
    {
        cnt++;
        cout << "Case " << cnt << ":" << endl;
        vector<int> v;
        while (t--)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }

        vector<int> sum;
        for (int i = 0; i < v.size() - 1; i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                sum.push_back(v[i] + v[j]);
            }
        }
        sort(sum.begin(), sum.end());
        int querys;
        cin >> querys;
        while(querys--)
        {
            int mid = 0;
            bool found(false);
            int q;
            cin >> q;
            int i = 0;
            int j = sum.size() - 1;
            while (i <= j)
            {
                mid = (i+j)/2;
                if (sum[mid] == q)
                {
                    found = true;
                    break;
                }
                else if (sum[mid] < q)
                {
                    i = mid + 1;
                }
                else
                {
                    j = mid - 1;
                }
            }
            int t;
            if (found)
            {
                cout << "Closest sum to " << q << " is " << sum[mid] ;
            }
            else if (i > mid)
            {
                if (i >= sum.size())
                {
                    t = sum[sum.size() - 1];
                }
                else
                {
                    t = (abs(sum[i] -q) > abs(sum[mid] - q)) ? sum[mid] : sum[i];
                }
            }
            else
            {
                if (j < 0)
                {
                    t = sum[0];
                }
                else
                {
                    t = (abs(sum[j] - q) > abs(sum[mid] -q)) ? sum[mid] : sum[j];
                }
            }
            if(!found)
            cout << "Closest sum to " << q << " is " << t;
            cout << "." << endl;
        }

    }
}
