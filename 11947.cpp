#include <stdio.h>


bool is_leap(int y)
{
  if (y % 4 == 0 && y % 100 != 0)return true;
  else if (y % 400 == 0) return true;
  else return false;
}
int days_for_month(int m, int y)
{
  static int month[2][13] = 
  {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
  };
  return month[is_leap(y)][m];
}
int main()
{
  int test_case;
  int i = 0;
  scanf("%d", &test_case);
  while (i++ < test_case)
  {
    int m, d, y;
    scanf("%2d%2d%4d", &m, &d, &y);
    int days = 280 + d;
    while (days > days_for_month(m, y))
    {
      days -= days_for_month(m, y);
      m = m % 12 + 1;
      if (m == 1) y++;
    }
    d = days;
    printf("%d %02d/%02d/%04d ", i, m, d, y);
    if ((d>=21 && m==1)  || (d<=19 && m==2)) printf("aquarius\n");
    if ((d>=20 && m==2)  || (d<=20 && m==3)) printf( "pisces\n");
    if ((d>=21 && m==3)  || (d<=20 && m==4)) printf( "aries\n");
    if ((d>=21 && m==4)  || (d<=21 && m==5)) printf( "taurus\n");
    if ((d>=22 && m==5)  || (d<=21 && m==6)) printf( "gemini\n");
    if ((d>=22 && m==6)  || (d<=22 && m==7)) printf( "cancer\n");
    if ((d>=23 && m==7)  || (d<=21 && m==8)) printf( "leo\n");
    if ((d>=22 && m==8)  || (d<=23 && m==9)) printf( "virgo\n");
    if ((d>=24 && m==9)  || (d<=23 && m==10)) printf( "libra\n");
    if ((d>=24 && m==10) || (d<=22 && m==11)) printf( "scorpio\n");
    if ((d>=23 && m==11) || (d<=22 && m==12)) printf( "sagittarius\n");
    if ((d>=23 && m==12) || (d<=20 && m==1))  printf( "capricorn\n");
  }
}
