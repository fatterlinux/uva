#include <stdio.h>

using namespace std;

class calc_date
{
  public:
  calc_date(int n, int day, int month, int year) : m_n(n), m_day(day), m_month(month), m_year(year) {}
  void date_show();
  private:
  int m_n, m_day, m_month, m_year;
  static const int zero_day(1), zero_month(1), zero_year(1998);
  int days_from_zero_date(int day, int month, int year);
  int date_from_zero_date(int n);
};

static const int zero_day, zero_month, zero_year;

void calc_date::date_show()
{
  int days = days_from_zero_date(m_day, m_month, m_year);
  days += m_n;
  date_from_zero_date(days);
}

int cacl_date::days_from_zero_date(int day, int month, int year)
{
  int y(zero_year);
  while (y)
  
}
