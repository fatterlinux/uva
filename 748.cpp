#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>//sprintf not defined

using namespace std;

const int max_len = 3000;//const 写错
struct bign
{
    int n[max_len];
    int len;
    
    bign()
    {
        memset(n, 0, sizeof(n));
        int len = 1;
    }
    ~bign(){}
    
    bign& operator=(const char* num)
    {
        len = strlen(num);
        for (int i = 0; i < len; i++)
        {
            n[i] = num[len - 1 - i] - '0';
        }
        
        return *this;
    }
    bign& operator=(int num)
    {
        char res[max_len];
        sprintf(res, "%d", num);
        *this = res;
        
        return *this;
    }
    bign(const char* num)
    {
        *this = num;
    }
    bign(int num)
    {
        *this = num;
    }
    string str() const
    {
        string res = "";
        for (int i = 0; i < len; i++)
        {
            res = char(n[i] + '0') + res;
        }
        if (res.empty())
        {
            res = "0";
        }
        return res;
    }
    void clean()
    {
        for (int i = len - 1; i > 0; i--)
        {
            if (n[i] == 0)
            {
                len--;
            }
            else
            {
                break;
            }
        }
        return;
    }
    bign operator*(const bign& b) const
    {
        bign c;
        c.len = len + b.len;
        
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j <b.len; j++)
            {
                c.n[i+j] += n[i]*b.n[j];
            }
        }
        
        for (int i = 0, g = 0; g || i < c.len; i++)
        {
            c.n[i] = g + c.n[i];
            g = c.n[i] / 10;
            c.n[i] = c.n[i] % 10;
        }
        
        c.clean();//没有对象调用clean
        
        return c;
    }
};

istream& operator>>(istream& in, bign& b)
{
    string res;
    cin >> res;
    b = res.c_str();
    return in;
}
ostream& operator<<(ostream& out, const bing& b)
{
    cout << b.str();
    return out;
}

int main()
{
    bign a, b;
    
    while (cin >> a >> b)
    {
        size_t dot = a.find('.');
        unsigned int dot_num = (6 - 1 - dot) * b;
        bign res = a;
        for (int i = 0; i < b - 1; i++)
        {
            bign b = a * res;
            res = b;
        }
        string s = res.str();
        if (s.size() <= dot_num)
        {
            int zero_times = dot_num - s.size();
            for (int i = 0; i <zero_times; i++)
            {
                s = '0' + s;
            }
            s = '.' + s;
        }
        else
        {
            size_t sub_idx = s.size() - dot_num;
            string ss = s.substr(0, sub_idx) + '.' + s.substr(sub_idx);
        }
        cout << ss <<endl;
    }
    
    return 0;
}
