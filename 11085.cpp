#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


const int max_queue = 8;
int qt[100][max_queue];
int cnt = 0;
int container[max_queue];

void search(int col)
{
    int i, j;
    if (col == max_queue)
    {
        for (int i = 0; i < max_queue; i++)
        {
            qt[cnt][i] = container[i] + 1;
        }
        cnt++;
        return;
    }
    for (i = 0; i < max_queue; i++)
    {
        container[col] = i;
        bool ok(true);
        for (j = 0; j < col; j++)
        {
            if (container[j] == container[col] ||
                    //(abs(container[j] - j) == abs(container[col] - col)) ||
                    j - container[j] == col - container[col] ||
                    (container[j] + j == container[col] + col))
            {
                ok = false;
                break;
            }
        }
        if (ok) search(col + 1);
    }
}

void info_print()
{
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < max_queue; j++)
        {
            printf("%d ", qt[i][j]);
        }
        printf("\n");
    }
    printf("queue result table size:[%d]\n", cnt);
    return;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("11085.in", "r", stdin);
#endif
    search(0);
    //info_print();
    int t = 0;
    while(scanf("%d", &container[0]) != EOF)
    {
        for (int i = 1; i < max_queue; i++)
        {
            scanf("%d", &container[i]);
        }
        int min_move = 99999999;
        for (int i = 0; i < cnt; i++)
        {
            int move = 0;
            for (int j = 0; j < max_queue; j++)
            {
                if (qt[i][j] != container[j]) move++;
            }
            if (move < min_move) min_move = move;
        }
        t++;
        printf("Case %d: %d\n", t, min_move);
    }
}
