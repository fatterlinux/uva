#include <stdio.h>
#include <vector>

using namespace std;
const int max_len = 120;
int main()
{
  char s[max_len];
  while (gets(s))
  {
    filter_blank(s);
    vector<int> var;
    vector<int> sum_elm;
    sum_elm = var_get(var, s);
    int value = sum_get(s, sum_elm);
    output(value, var);
  }
  return 0;
}
