#include <iostream>
#include <math.h>

using namespace std;

long long sum(int n)
{
  return (long long)pow(double(n), 2);
}

int main()
{
  int test_case;
  cin >> test_case;
  while (test_case--)
  {
    int n;
    cin >> n;
    
    long long sum0, sum1;
    sum1 = 0;
    sum0 = 0;
    int i;//层数
    for (i = 1; n > sum1; i++)
    {
      sum0 = sum1;
      sum1 = sum(i);
    }
    long long num = n - sum0;
    bool half_more = false;
    long long center = (2*i)-1)/2 + 1;
    long long idx = abs(num - center);
    if (num > center) {half_more = true; idx = num - center;}
    else {idx = num;}
    long long j;
    if (half_more)
    {
     
      for (j = center - 1; idx != 0; j--, idx--);
      if (i % 2)
      cout << j << " " << center << endl;
      else
      {
        cout << center << " " << j << endl;
      }
    }
    else
    {
      for (j = 1; idx != 0; j++, idx--);
      if (i % 2)
      cout << center << " " << j << endl;
      else
      {
        cout << j << " " << center << endl;
      }
    }
  }
}
