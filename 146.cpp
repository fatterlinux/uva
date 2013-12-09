#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
  char buf[55];
  while (scanf("%s", buf))
  {
    if (buf[0] == '#')
    {
      break;
    }
    if (next_permutation(buf, buf+strlen(buf)))
    {
      printf("%s\n", buf);
    }
    else
    {
      printf("No Successor\n");
    }
  }
  return 0;
}
