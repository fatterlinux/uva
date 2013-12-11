#include <stdio.h>

const int max_len = 10010;
int ans[max_len];
int tmp[max_len];

void reset()
{
  memset(ans, 0, sizeof(ans));
  memset(tmp, 0, sizeof(tmp));
}
void solve(int* ans, int l , int r)
{
  if (l == r) return;
  int cnt = l;
  for (int i = l; i <= r; i += 2)
  {
    tmp[cnt++] = ans[i];
  }
  for (int i = l + 1; i <= r; i += 2)
  {
    tmp[cnt++] = ans[i];
  }
  for (int i = l; i <= r; i++)
  {
    ans[i] = tmp[i];
  }
  solve(ans, l, (l+r)/2);
  solve(ans, (l+r)/2+1, r);
  return;
}
void init(int* ans, int n)
{
  for (int i = 0; i < n; i++)
  {
    ans[i] = i;
  }
}
void output(int* ans, int n)
{
  bool first(true);
  for (int i = 0; i < n; i++)
  {
    if (first)
    {
      first = false;
    }
    else
    {
      printf(" ");
    }
    printf("%d", ans[i]);
  }
  printf("\n");
}
int main()
{
  int n;
  while (scanf("%d", &n) != EOF, n)
  {
    reset();
    init(ans, n);
    solve(ans, 0, n - 1);
    output(ans, n);
  }
  return 0;
}
