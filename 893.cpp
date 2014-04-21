#include <stdio.h>

using namespace std;

class calc_date
{
  public:
  calc_date(int n, int day, int month, int year) : m_n(n), m_day(day), m_month(month), m_year(year) {}
  void date_show();
  private:
  int m_n, m_day, m_month, m_year;
  
};

void calc_date::date_show()
{
  
}
