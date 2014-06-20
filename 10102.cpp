#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;


int** square_create(int n)
{
    int** a = new int*[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
    }
    return a;
}
void square_delete(int** a, int n)
{
    if (a)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i])
            delete [] a[i];
        }
        delete [] a;
    }
}
void square_print(int** a, int n)
{
    if (a)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

typedef struct
{
    int x, y, cnt;
}node;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int bfs(int** a, int m, int n, int t)
{
    int** visit = square_create(t);
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
            visit[i][j] = 0;
    }
     queue<node> q;
    node ttt;
    ttt.x = m; ttt.y = n; ttt.cnt = 0;
    visit[m][n] = 1;
    q.push(ttt);
    int min_step = 9999999;
    while (!q.empty())
    {
        node tmp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if (x < 0 || x >= t || y < 0 || y >=t || visit[x][y]) continue;
            node tt;
            tt.x = x;
            tt.y = y;
            tt.cnt = tmp.cnt + 1;
            visit[x][y] = 1;
            q.push(tt);
            if (a[x][y] == 3)
            {
                min_step = tmp.cnt + 1;
                goto out;
            }
        }
    }
out:
    square_delete(visit, t);
    return min_step;

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int t;
    while (cin >> t)
    {
        int** a = square_create(t);
        for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < t; j++)
            {
                char c;
                cin >> c;
                a[i][j] = c - '0';
            }
        }
        //square_print(a, t);
        int min = 0;
        for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < t; j++)
            {
                if (a[i][j] == 1)
                {
                    int tmp = bfs(a, i, j, t);
                    if (min < tmp)
                    {
                        min = tmp;
                    }
                }
            }
        }
        cout << min << endl;
        square_delete(a, t);
    }
    return 0;
}
