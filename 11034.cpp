#include <iostream>
#include <queue>

using namespace std;

int main()
{
  int test_case;
  cin >> test_case;
  while (test_case--)
  {
    //input
    int length, cars;
    cin >> length >> cars;
    length *= 100;
    queue<int> L, R;
    while (cars--)
    {
      string derection;
      int car_len;
      
      cin >> car_len >> derection;
      if (derection == "left")
      {
        L.push(car_len);
      }
      else
      {
        R.push(car_len);
      }
    }
    int cross_times = 0;
    while (1)
    {
      int l = length;
      if (L.empty() && R.empty()) break;
      while (!L.empty() && L.front() <= l)
      {
        l -= L.front();
        L.pop();
      }
      cross_times++;
      if (L.empty() && R.empty()) break;
      l = length;
      while (!R.empty() && R.front() <= l)
      {
        l -= R.front();
        R.pop();
      }
      cross_times++;
    }
    cout << cross_times <<endl;
  }
  return 0;
}
