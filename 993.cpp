#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  while (n--)
  {
    int num;
    scanf("%d", &num);
    if (num == 1)
    {
      printf("1\n");
      continue;
    }
    vector<int> v;
    for (int i = 9; i > 1; i--)
    {
      while (num % i == 0)
      {
        v.push_back(i);
        num /= i;
      }
      if (num == 1) break;
    }
    if (num != 1)
    {
      printf("-1\n");
    }
    else
    {
      sort(v.begin, v.end());
      for (int i = 0; i < v.size(); i++)
      {
        printf("%d", v[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
