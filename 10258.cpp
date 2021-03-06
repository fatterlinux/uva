#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <sstream>
#include <stdio.h>
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
  int solved_num;
  bool submission;
  unsigned time;
  problem_t p[PROBLEM];
}contest_record;
static contest_record contestants[CONTESTANT];

static bool comp_func(const contest_record& a, const contest_record& b);
int main()
{
  int test_case;
  cin >> test_case;
  string s;
  getline(cin, s);
  getline(cin, s);
  bool first = true;
  while (test_case--)
  {
    if (first) first = false;
    else cout <<endl;
    memset(contestants, 0, sizeof(contestants));
    for (int i = 0; i < CONTESTANT; i++)
    {
      contestants[i].index = i;
    }
    while (getline(cin, s) && !s.empty())
    {
      int n, s_i, s_t;
      char s_s;
      stringstream ss;
      ss << s;
      ss >> n >> s_i >> s_t >> s_s;
      contestants[n].submission = true;
      if (!contestants[n].p[s_i].solved)
      {
        if (s_s == 'C')
        {
          contestants[n].p[s_i].solved = true;
          contestants[n].p[s_i].time += s_t;
        }
        else if (s_s == 'I')
        {
          contestants[n].p[s_i].time += 20;
        }
      }
    }
    for (int i = 0; i < CONTESTANT; i++)
    {
      if (contestants[i].submission)
      {
        for (int j = 1; j < PROBLEM; j++)
        {
          if (contestants[i].p[j].solved)
          {
            contestants[i].solved_num++;
            contestants[i].time += contestants[i].p[j].time;
          }
        }
      }
    }
    sort(contestants, contestants+CONTESTANT, comp_func);
    for (int i = 0; i < CONTESTANT; i++)
    {
      if (contestants[i].submission)
      {
        printf("%d %d %d\n", contestants[i].index, contestants[i].solved_num, contestants[i].time);
      }
    }
  }
  return 0;
}
static bool comp_func(const contest_record& a, const contest_record& b)
{
  if (a.solved_num > b.solved_num) return true;
  else if (a.solved_num == b.solved_num && a.time < b.time) return true;
  else if (a.solved_num == b.solved_num && a.time == b.time && a.index < b.index) return true;
  else return false;
}
