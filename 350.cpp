#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
  int Z,I,M,L;
  
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
    while (1)
    {
      cycle[idx] = (Z*L+i)%M;
      L = cycle[idx];
      for (int i = 0; i < idx; i++)
      {
        if (cycle[i] == cycle[idx])
        {
          c = idx - i;
        }
      }
    }
  }
}
