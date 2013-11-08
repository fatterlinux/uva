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
    
    bign operator=(cosnt char* num)
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
