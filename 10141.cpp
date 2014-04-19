#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class proposal
{
    public:
        proposal(string name, double price, int compliant):m_name(name), m_price(price), m_compliant(compliant) {}
        
        string name() const
        {
            return m_name;
        }
       
        friend ostream& operator<<(ostream& out, const proposal& p);
        friend bool operator<(const proposal& a, const proposal& b)
        {
            if ((a.m_compliant > b.m_compliant))
            {
                return true;
            }
            else if (a.m_compliant == b.m_compliant && (a.m_price < b.m_price))//等于时，不应该
            {
                return true;
            }
            return false;
        }
    private:
        string m_name;
        int m_compliant;
        double m_price;
};

ostream& operator<<(ostream& out, const proposal& p)
{
    out << p.m_name << "\t" << p.m_compliant << "\t" << p.m_price;
    return out;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int met_num;
    int proposal_num;
    int cnt = 0;
    bool need_print = false;
    while (scanf("%d %d", &met_num, &proposal_num), met_num)
    {
        if (need_print)
        {
            cout << endl;
        }
        else
        {
            need_print = true;
        }
        cnt++;
        vector<proposal> v;
        string s;
        getline(cin, s);
        while (met_num--)
        {
            getline(cin, s);
        }
        while (proposal_num--)
        {
            string name;
            double price;
            int compliant;

            getline(cin, name);
            cin >> price >> compliant;
            proposal p(name, price, compliant);
            v.push_back(p);
            //cout << p << endl;
            getline(cin, s);
            while (compliant--)
            {
                getline(cin, s);
            }
        }
        stable_sort(v.begin(), v.end());//这里出bug了，不是稳定排序
        cout << "RFP #" << cnt << endl;
        cout << v[0].name() << endl;

    }
    return 0;
}
