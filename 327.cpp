#include <stdio.h>
#include <vector>
#include <ctypes.h>

using namespace std;
const int max_len = 120;
vector<int> var_get(vector<char>& var, char s[]);
int sum_get(char* s, vector<int>& elm);
void output(int value, vector<char>& var);
void filter_blank(char* s);
int main()
{
  char s[max_len];
  while (gets(s))
  {
    filter_blank(s);
    vector<char> var;
    vector<int> sum_elm;
    int map[26];
    for (int i = 0; i < 26; i++)
    {
      map[i] = 0;
    }
    sum_elm = var_get(var, s);
    int value = sum_get(s, sum_elm);
    output(value, var);
  }
  return 0;
}

vector<int> var_get(vector<char>& var, char* s)
{
  for (int i = 0; i < strlen(s); i++)
  {
    if (islower(s[i]))
    {
      if (i >= 2 && is_pre_double_operator(s, i))
      {}
      else if ((i <= strlen(s) - 3) && is_post_double_operator(s, i))
      {}
      else
      {}
    }
  }
}
void filter_blank(char* s)
{
  int i, j;
  for (i = j = 0; i < strlen(s); i++)
  {
    if (!isblank(s[i]))
    {
      s[j++] = s[i];
    }
  }
  s[j] = '\0';
  return;
}
