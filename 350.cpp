#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
  int Z,I,M,L;
  int test_case = 0;
  while (cin >> Z >> I >> M >> L)//(z*l+i)%m
  {
    if (!Z && !I && !M && !L)
    {
      break;
    }
    
    int cycle[10000];
    memset(cycle, 0, 10000);
    int idx = 0;
    int c = 0;
    bool found = false;
    while (1)
    {
      cycle[idx] = (Z*L+I)%M;
      L = cycle[idx];
      for (int i = 0; i < idx; i++)
      {
        if (cycle[i] == cycle[idx])
        {
          c = idx - i;
          found = true;
          break;
        }
      }
      if (found)
      {
        break;
      }
      idx++;
    }
    test_case++;
    printf("Case %d: %d\n", test_case, c);
  }
  return 0;
}
