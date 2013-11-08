#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

const int max_len = 1000;
struct bign
{
    int len;
    int s[max_len];
    bign()
    {
        len = 1;
        memset(s, 0, sizeof(s));
    }
    ~bign(){}
    
    bign operator=(const char* num)
    {
        len = strlen(num);
        
        for (int i = 0; i < len; i++)
        {
            s[i] = num[len - 1 - i] - '0';
        }
        
        return *this;
    }
    
    bign operator=(int num)
    {
        char res[max_len];
        sprintf(res, "%d", num);
        *this = res;
        
        return *this;
    }
    
    void clean()
    {
        while (len > 1 && !s[len - 1]) len--;
        return ;
    }
    
    bign operator*(const bign& b)
    {
        bign c;
        c.len = len + b.len;
        
        for (int i = 0; i <len; i++)
        {
            for (int j = 0; j <b.len; j++)
            {
                c.s[i+j] += s[i] * b.s[j];
            }
        }
        
        for (int i = 0; i < c.len - 1; i++)
        {
            s[i+1] += s[i] / 10;
            s[i] = s[i] % 10;
        }
        c.clean();
        
        return c;
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
        string res;
        for (int i = 0; i <len; i++)
        {
            res = char(s[i] + '0') + res;
        }
        if (res.empty()) res = "0";
        return res;
    }
};

istream& operator>>(istream& in, bign& x)
{
    string res;
    in >> res;
    x = res.c_str();
    
    return in;
}

ostream& operator<<(ostream& out, const bign& x)
{
    cout << x.str();
    return out;
}

int main()
{
    bign a, b;
    
    while (cin >> a >> b)
    {
        
        cout << a*b << endl;
    }
    return 0;
}
