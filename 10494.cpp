#include <iostream>
#include <string.h>

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

void my_mod(string& a, long long b)
{
    long long g = 0;
    for (int i = 0; i < a.size(); i++)
    {
        g = 10*g + a[i] - '0';
        g = g % b;
    }
    cout << g << endl;
    return;
}
void my_div(string& a, long long b)
{
    long long g = 0;
    int num[10000];
    int i = 0;
    memset(num, 0, sizeof(num));
    for (; i < a.size(); i++)
    {
        g = 10*g + a[i] - '0';
        num[i] = g / b;
        g = g % b;
    }
    int valid_idx = 0;
    for (; valid_idx < i; valid_idx++)
    {
        if (a[valid_idx]) break;
    }
    if (valid_idx == i)
    {
        cout <<0 << endl;
    }
    for (; valid_idx < i; valid_idx++)
    {
        cout << num[valid_idx];
    }
    cout <<endl;
    
    return;
}
