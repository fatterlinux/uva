#include <stdio.h>

using namespace std;

class calc_date
{
  public:
  calc_date(int n, int day, int month, int year) : m_n(n), m_day(day), m_month(month), m_year(year) {}
  void date_show();
  private:
  int m_n, m_day, m_month, m_year;
  int days_from_zero_date();
  void date_from_zero_date(int n);
  int days_for_year(int y);
  int days_for_month(int m, int y);
  bool is_leap(int y);
};

bool calc_date::is_leap(int y)
{
  if (y % 4 == 0 && y % 100 != 0) return true;
  else if (y % 400 == 0) return true;
  else return false;
}
int calc_date::days_for_year(int y)
{
  return is_leap(y) ? 366 : 365;
}
int calc_date::days_for_month(int m, int y)
{
  static int m_month[2][13] = 
  {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  };
  return m_month[is_leap(y)][m];
}


void calc_date::date_show()
{
  date_from_zero_date(days_from_zero_date());
}
int calc_date::days_from_zero_date()
{
  int y(1998), m(1), d(1);
  int days(m_n);
  while (y < m_year)
  {
    days += days_for_year(y);
    y++;
  }
  while (m < m_month)
  {
    days += days_for_month(m, y);
    m++;
  }
  days += m_day - 1;
  return days;
}
void calc_date::date_from_zero_date(int n)
{
  int y(1998), m(1), d(1);
  while (n >= days_for_year(y))
  {
    n -= days_for_year(y);
    y++;
  }
  while (n >= days_for_month(m, y))
  {
    n -= days_for_month(m, y);
    m++;
  }
  d += n;
  printf("%d %d %d\n", d, m, y);
}

int main()
{
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int n, d, m, y;
  while (scanf("%d %d %d %d", &n, &d, &m, &y), !(n == 0&&d == 0&&m == 0&&y == 0))
  {
    
    calc_date c(n, d, m, y);
    c.date_show();
  }
  return 0;
}
