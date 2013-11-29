#include <stdio.h>
#include <vector>
#include <ctype.h>
#include <deque>
#include <assert.h>
#include <string.h>

using namespace std;
const int max_len = 120;
void var_get(vector<char>& var, char s[], int* map);
int sum_get(char* s, deque<int>& elm, int* map);
void output(int value, vector<char>& var, int* map);
void filter_blank(char* s);
deque<int> sum_elm;
int main()
{
  char s[max_len];
  while (gets(s))
  {
    printf("Expression: %s", s);
    filter_blank(s);
    vector<char> var;
    int map[26];
    for (int i = 0; i < 26; i++)
    {
      map[i] = i + 1;
    }
    var_get(var, s, map);
    int value = sum_get(s, sum_elm, map);
    output(value, var, map);
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
int sum_get(char* s, deque<int>& sum_elm, int* map)
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
bool is_pre_double_operator(char* s, int i)
{
  return ((s[i-1] == '+' && s[i-2] == '+') || (s[i-1] == '-' && s[i-2] == '-')); 
}
bool is_post_double_operator(char* s, int i)
{
  return ((s[i+1] == '+' && s[i+2] == '+') || (s[i+1] == '-' && s[i+2] == '-')); 
}
void var_get(vector<char>& var, char* s, int* map)
{
  deque<int>& v = sum_elm;
  for (int i = 0; i < strlen(s); i++)
  {
    if (islower(s[i]))
    {
      var.push_back(s[i]);
      if (i >= 2 && is_pre_double_operator(s, i))
      {
        if (s[i-1] == '+')
        map[s[i]-'a']++;
        else
        map[s[i]-'a']--;
        v.push_back(map[s[i] - 'a']);
        s[i-1] = s[i-2] = ' ';
      }
      else if ((i <= strlen(s) - 3) && is_post_double_operator(s, i))
      {
        v.push_back(map[s[i] - 'a']);
        if (s[i+1] == '+')
        map[s[i]-'a']++;
        else
        map[s[i]-'a']--;
        
        s[i+1] = s[i+2] = ' ';
      }
      else
      {
        v.push_back(map[s[i] - 'a']);
      }
    }
  }
  return ;
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
