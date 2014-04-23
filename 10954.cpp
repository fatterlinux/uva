#include <iostream>
#include <vector>
#include <queue>
#include <functional>//greater

using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        priority_queue<int, vector<int>, greater<int> > q;
        int x = n;
        while (x--)
        {
            int t;
            cin >> t;
            q.push(t);
        }
        int sum = 0;
        while (--n)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            sum += a + b;
            q.push(a + b);
        }
        cout << sum << endl;
    }
    return 0;
}
