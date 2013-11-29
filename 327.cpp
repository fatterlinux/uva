#include <stdio.h>
#include <vector>
#include <ctypes.h>
#include <deque>
#include <assert.h>

using namespace std;
const int max_len = 120;
deque<int> var_get(vector<char>& var, char s[]);
int sum_get(char* s, vector<int>& elm);
void output(int value, vector<char>& var);
void filter_blank(char* s);
int main()
{
  char s[max_len];
  while (gets(s))
  {
    printf("Expression: %s", s);
    filter_blank(s);
    vector<char> var;
    vector<int> sum_elm;
    int map[26];
    for (int i = 0; i < 26; i++)
    {
      map[i] = i + 1;
    }
    sum_elm = var_get(var, s);
    int value = sum_get(s, sum_elm);
    output(value, var);
  }
  return 0;
}
void output(int value, vector<char> var, int* map)
{
  printf("    %d\n", value);
  for (int i = 0; i < var.size(); i++)
  {
    printf("    %c = %d\n", var[i], map[var[i]-'a']);
  }
}
int sum_get(char* s, deque<int>& sum_elm)
{
  
  for (int i = 0; i < strlen(s); i++)
  {
    if (s[i] == '+')
    {
      int a = sum_elm[0];
      int b = sum_elm[1];
      sum_elm.pop_front();
      sum_elm.pop_front();
      sum_elm.push_front(a+b);
    }
    else if (s[i] == '-')
    {
      int a = sum_elm[0];
      int b = sum_elm[1];
      sum_elm.pop_front();
      sum_elm.pop_front();
      sum_elm.push_front(a-b);
    }
  }
  assert(sum_elm.size() == 1);
  return sum_elm[0];
}
deque<int> var_get(vector<char>& var, char* s)
{
  deque<int> v;
  for (int i = 0; i < strlen(s); i++)
  {
    if (islower(s[i]))
    {
      var.push_back(s[i]);
      if (i >= 2 && is_pre_double_operator(s, i))
      {
        map[s[i]-'a']++;
        v.push_back(map[s[i] - 'a']);
        s[i-1] = s[i-2] = ' ';
      }
      else if ((i <= strlen(s) - 3) && is_post_double_operator(s, i))
      {
        v.push_back(map[s[i] - 'a']);
        map[s[i]-'a']++;
        s[i+1] = s[i+2] = ' ';
      }
      else
      {
        v.push_back(map[s[i] - 'a']);
      }
    }
  }
  return v;
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
