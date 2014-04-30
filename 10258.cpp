#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <sstring>
#define CONTESTANT  101
#define PROBLEM     10
using namespace std;
typedef struct
{
  unsigned time;
  bool solved; 
}problem_t;
typedef struct
{
  int index;
  int solved;
  bool submission;
  unsigned time;
  problem_t p[PROBLEM];
}contest_record;
static contest_record contestants[CONTESTANT];

int main()
{
  int test_case;
  cin >> test_case;
  string s;
  getline(cin, s);
  bool first = true;
  while (test_case--)
  {
    if (first) first = false;
    else cout <<endl;
    while (get_line(cin, s) && !s.empty())
    {
      int n, s_i, s_t;
      char s_s;
      stringstream ss;
      ss << s;
      ss >> n >> s_i >> s_t >> s_s;
      
    }
  }
}
