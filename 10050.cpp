#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  int test_case;
  cin >> test_case;
  
  while (test_case--)
  {
    bool days[3651];
    memset(days, 0, sizeof(days));
    int party_num, days_num;
    cin >> days_num;
    cin >> party_num;
    while (party_num--)
    {
      int step;
      cin >> step;
      for (int i = step; i <= days_num; i += step)
      {
        days[i] = true;
      }
    }
    int cnt = 0;
    for (int i = 1; i <= days_num; i++)
    {
      if (days[i] && (i%7==0) && (i%7) == 6)
      {
        cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
