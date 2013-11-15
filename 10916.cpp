#include <iostream>
#include <math.h>

using namespace std;

int get_bit_num(int year)
{
  int n = 2 + (year-1960)/10;
  return pow(2, n);
}

int main()
{
  int n;
  while (cin >> n)
  {
    if (!n) break;
    int bit_num = get_bit_num(n);
    double sum = 0;
    for (int i = 1; sum < bit_num; i++)
    {
      sum += log10(i)/1og10(2);
    }
    cout << i - 2 << endl;
  }
  return 0;
}
