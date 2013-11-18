#include <iostream>
#include <string>
#include <stack>
uisng namespace std;


struct matrix
{
  int m_row, m_column;
  matrix(int row = 0, int column = 0):m_row(row),m_column(column)
  {}
  matrix(const matrix& a)
  {
    *this = a;
  }
  matrix& operator =(const matrix&a)
  {
    m_row = a.m_row;
    m_column = a.m_column;
    return *this;
  }
  operator bool() const
  {
    return ((m_row != -1) && (m_column != -1) && !is_sep());
  }
  bool is_sep() const
  {
    return ((m_row != -2) && (m_columnt != -2));
  }
  matrix operator *(const matrix& a) const
  {
    matrix c;
    if (m_column != a.m_row)
    {
      c.m_row = c.column = -1;
      return c;
    }
    c.m_row = m_row;
    c.m_column = a.m_column;
    return c;
  }
  int mul_times_get(const matrix& a) const
  {
    return m_row*a.m_column*m_column;
  }
};

int main()
{
  int n;
  matrix map[26];
  while (n--)
  {
    char c;
    int row, column;
    map[int(c - 'A')] = matrix(row, column);
  }
  string s;
  while (cin >> s)
  {
    s.insert(0, "(");
    s.append(")");
    stack<matrix> ss;
    int cnt(0);
    bool err_flag(false);
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == '(')
      {
        ss.push(matrix(-2, -2));
      }
      else if (isalpha(s[i]))
      {
        ss.push(map[s[i] - 'A']);
      }
      else if (s[i] == ')')
      {
        matrix res(ss.top());
        ss.pop();
        assert(!res.is_sep());
        while (1)
        {
          matrix m(ss.top());
          ss.pop();
          if (m.is_sep())
          {
            ss.push(res);
            break;
          }
          else
          {
            matrix t(res);
            res = m * t;
            if (!res)
            {
              err_flag = true;
              break;
            }
          }
        }
      }
      if (err_flag) break;
    }
    if (err_flag)
    {
      cout << "error" << endl;
    }
    else
    {
      cout << cnt << endl;
    }
  }
}
