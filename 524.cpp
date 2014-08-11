/*
 * =====================================================================================
 *
 *       Filename:  524.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年08月11日 21时46分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  loop (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int max_n = 16;
int res[max_n];
int N;
const int prime_num = 100;
int prime[prime_num];
bool __is_prime(int n)
{
    if (n == 0 || n == 1) return false;
    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}
void prime_table()
{
   for (int i = 0; i < prime_num; i++)
   {
       prime[i] = __is_prime(i);
   } 
}
void prime_table_print()
{
    printf("prime table:\n");
    for (int i = 0; i < prime_num; i++)
    {
        if (prime[i]) printf("%d ", i);
    }
    printf("\n");
}
bool is_prime(int i)
{
    return prime[i];
}
void backtracking(int cur)
{
    if (cur == N)
    {
        if (is_prime(res[N-1] + res[0]))
        {
            for (int i = 0; i < N; i++)
            {
                printf("%d ", res[i]);
            }
            printf("\n");
        }
    }
    else for (int i = 1; i < N; i++)
    {
        res[cur] = i + 1;
        bool ok(true);
        for (int j = 1; j < cur; j++)
        {
            if (res[j] == res[cur])
            {
                ok = false;
                break;
            }
        }
        if (cur != 0)
        {
            if (!is_prime(res[cur-1]+res[cur])) ok = false;
        }
        if (ok) backtracking(cur + 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("524.in", "r", stdin);
#endif
    int cnt = 0;
    prime_table();
    //prime_table_print();
    while(scanf("%d", &N) != EOF)
    {
        cnt++;
        printf("Case %d:\n", cnt);
        res[0] = 1;
        backtracking(1);
        cout << endl;
    }
    return 0;
}
