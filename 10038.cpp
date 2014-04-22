#include <stdio.h>
#include <math.h>

#define max_n 3001
bool map[max_n];
long long a[max_n];
int main()
{
  int n;
  while (scanf("%d", &n) != EOF)
  {
    memset(map, 0, sizeof(map));
    
    for (int i = 0; i < n; i ++)
    {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++)
    {
      long long t = abs(a[i-1], a[i]);
      if (t < (long long)n) map[t] = true;
    }
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
      if (!map[i])
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      printf("Jolly\n");
    }
    else
    {
      printf("Not jolly");
    }
  }
  return 0;
}
