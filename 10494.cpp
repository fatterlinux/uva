#include <iostream>
#include <string.h>
#include <string>

using namespace std;
void my_div(const string& a, long long b);
void my_mod(const string& a, long long b);
int main()
{
    string a;
    long long b;
    char c;
    
    while (cin >> a >> c >> b)
    {
        if (c == '/')
        {
            my_div(a, b);
        }
        else
        {
            my_mod(a, b);
        }
    }
    return 0;
}

void my_mod(const string& a, long long b)
{
    long long g = 0;
    for (long long  i = 0; i < a.size(); i++)
    {
        g = 10*g + a[i] - '0';
        g = g % b;
    }
    cout << g << endl;
    return;
}
/*
模拟手动除法
e.g.:110/20  
1）1/20不够，1*10 + 1 = 11
2）11/20 不够，11*10 + 0= 110
3）110/20够了，计算结果
*/
void my_div(const string& a, long long b)
{
    long long g = 0;
    int num[10000];
    long long  i = 0;
    memset(num, 0, sizeof(num));
    for (; i < a.size(); i++)
    {
        g = 10*g + a[i] - '0';
        num[i] = g / b;
        g = g % b;
    }
    long long  valid_idx = 0;
    for (; valid_idx < i; valid_idx++)
    {
        if (num[valid_idx]) break;
    }
    if (valid_idx == i)
    {
        cout << 0 << endl;
        return;//一个return导致多次wa啊
    }
    for (; valid_idx < i; valid_idx++)
    {
        cout << num[valid_idx];
    }
    cout <<endl;
    
    return;
}
