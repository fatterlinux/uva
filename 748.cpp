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
};
