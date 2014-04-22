#include <stdio.h>
using namespace std;
static bool a[10001];

int main()
{
  int buddies, report;
  while (scanf("%d %d", &buddies, &report), !(buddies == 0 && report == 0))
  {
    for (int i = 1; i <= buddies; i++)
    {
      a[i] = true;
    }
    while (report--)
    {
      int l, r;
      cin >> l >> r;
      for (int j = l; j <= r; j++)
      {
        a[j] = false;
      }
      int l_live = 0, r_live = 0;
      for (int j = l - 1; j >= 1; j--)
      {
        if (a[j])
        {
          l_live = j;
          break;
        }
      }
      for (int j = r + 1; j <= boddies; j++)
      {
        if (a[j])
        {
          r_live = j;
          break;
        }
      }
      if (l_live) printf("%d", l_live);
      else printf("*");
      printf(" ");
      if (r_live) printf("%d", r_live);
      else printf("*");
      printf("\n");
      
    }
    printf("-");
  }
}
