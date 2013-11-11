#include <iostream>
#include <string>
#include <string.h>

using namespace std;

cosnt int max_len = 3000;
class bign
{
    char n[max_len];
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
            n[i] = num[len - 1 - i];
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
            res = n[i] + res;
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
                c.n[i+j] = n[i]*b.n[j];
            }
        }
        
        for (int i = 0, g = 0; g || i < c.len; i++)
        {
            s[i] = g + s[i];
            g = s[i] / 10;
            s[i] = s[i] % 10;
        }
        
        clean();
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
        cout << a * b <<endl;
    }
    
    return 0;
}
