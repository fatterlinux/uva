#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

struct node
{
  double a, b, c;
  node()
  {
    a = b = c = 0;
  }
};

int distance_get(node& a, node& b)
{
  return int(sqrt(pow(a.a - b.a, 2) + pow(a.b - b.b, 2) + pow(a.c - b.c, 2)));
}
const int max_size = 5500;
node N[max_size];
int idx = 0;
int res[10];
int main()
{
  double a, b, c;
  
  while (cin >> a >> b >> c)
  {
    if (!int(a) && !int(b) && !int(c))
    {
      break;
    }
    N[idx].a = a;
    N[idx].b = b;
    N[idx].c = c;
    idx++;
  }
  for (int i = 0; i < idx; i++)
  {
    int min = 0xffffffff;
    for (int j = 0; j < idx; j++)
    {
      if (i == j) continue;
      int t = distance_get(N[i], N[j]);
      if (min > t)
      {
        t = min;
      }
    }
    if (min >= 0 && min <= 9)
    {
      res[min]++;
    }
  }
  for (int i = 0; i < 10; i++)
  {
    printf("%4d", res[i]);
  }
  
  return 0;
}
