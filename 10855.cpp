#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


int square_equal(char** a, int a_n, char** b, int b_n)
{
    int cnt = 0;
    for (int i = 0; i <= a_n - b_n; i++)
    {
        for (int m = 0; m <= a_n - b_n; m++)
        {
            bool match(true);
            for (int k = 0; k < b_n; k++)
            {
                for (int j = 0; j < b_n; j++)
                {
                    if (a[i+k][m+j] != b[k][j])
                    {
                       match = false; 
                    }
                }
            }
            if (match) cnt++;
        }
    }
    return cnt;
}
char** square_create(int n)
{
    char** a = new char* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new char [n];
    }
    return a;
}
void square_dtor(char** a, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete [] a[i];
    }
    delete [] a;
}
void square_print(char** a, int n)
{
    cout << "print begin" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "print end" << endl;
}
char** rotated90(char** a, int n)
{
    char** b = square_create(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = a[n-1-j][i];
        }
    }
    //square_print(b, n);

    return b;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int N, n;
    while (cin >> N >> n, N || n)
    {
        char** a = square_create(N);
        char** b = square_create(n);
        string s;
        getline(cin, s);
        int line = 0;
        while (line < N)
        {
            for (int i = 0; i < N; i++)
            {
                cin >> a[line][i];
            }
            getline(cin, s);
            line++;
        }
        //square_print(a, N);
        line = 0;
        while (line < n)
        {
            for (int i = 0; i < n; i++)
            {
                cin >> b[line][i];
            }
            getline(cin, s);
            line++;
        }
        //square_print(b, n);
#if 1
        int cnt1 = square_equal(a, N, b, n);
        char** c = rotated90(a, N);
        
        int cnt2 = square_equal(c, N, b, n);
        char** d = rotated90(c, N);
        int cnt3 = square_equal(d, N, b, n);
        char** e = rotated90(d, N);
        int cnt4 = square_equal(e, N, b, n);
        printf("%d %d %d %d\n", cnt1, cnt2, cnt3, cnt4);
        square_dtor(a, N);
        square_dtor(b, n);
        square_dtor(c, N);
        square_dtor(d, N);
        square_dtor(e, N);
#endif
    }
    return 0;
}
