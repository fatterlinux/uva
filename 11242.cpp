#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int f;
    while (cin >> f && f)
    {
        int r;
        cin >> r;
        vector<int> fronts;
        while (f--)
        {
            int n;
            cin >> n;
            fronts.push_back(n);
        }
        vector<int> rears;
        while (r--)
        {
            int n;
            cin >> n;
            rears.push_back(n);
        }
        vector<double> ad;
        for (vector<int>::iterator it_rear = rears.begin(); it_rear != rears.end();it_rear++)
        {
            for (vector<int>::iterator it_front = fronts.begin(); it_front != fronts.end();it_front++)
            {
                ad.push_back(1.0*(*it_rear)/(*it_front));
            }
        }
        sort(ad.begin(), ad.end());
        double m = 0;
        for (int i = 0; i < ad.size() - 1; i++)
        {
            int j = i + 1;
            double tmp = ad[j] / ad[i];
            if (tmp > m)
            {
                m = tmp;
            }
        }
        printf("%.2f\n", m);
    }
    return 0;
}
