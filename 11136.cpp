#include <iostream>
#include <queue>
using namespace std;

int main()
{
  int test_case;
  while (cin >> test_case, test_case)
  {
    priority_queue<int> max_heap;
    priority_queue<int> min_heap;
    long long cost = 0;
    while (test_case--)
    {
      int t;
      cin >> t;
      while (t--)
      {
        int n;
        cin >> n;
        max_heap.push(n);
        min_heap.push(n);
      }
      cost += max_heap.top() - min_heap.top();
      max_heap.pop();
      min_heap.pop();
    }
    cout << cost << endl;
  }
  return 0;
}
