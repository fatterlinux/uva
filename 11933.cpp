#include <iostream>
#include <string.h>
#include <bitset>

using namespace std;

static int cnt[35];
int main()
{
  int num;
  while (cin >> num, num)
  {
    memset(cnt, 0, sizeof(cnt));
    bitset<35> bb(num);
    int index = 1;
    for (int i = 0; i < 35; i++)
    {
      if (bb.test(i)) cnt[index++] = i;
    }
    int a, b;
    a = b = 0;
    for (int i = 1; i < index; i += 2)
    {
      a |= (1 << cnt[i]);
    }
    for (int i = 2; i < index; i+=2)
    {
      b |= (1 << cnt[i]);
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
