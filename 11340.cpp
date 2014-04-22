#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

static int ascii[256];

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
      memset(ascii, 0, sizeof(ascii));
      int v_tbl;
      cin >> v_tbl;
      while (v_tbl--)
      {
        string s;
        getline(cin, s);
        unsigned char c;//ascii可能255，不能用char索引；另外数组索引时区分正负数的，不会转化成整数
        int v;
        scanf("%c %d", &c, &v);
        ascii[c] = v;
      }
      int lines;
      cin >> lines;
      string s;
      getline(cin, s);
      double sum(0);
      while(lines--)
      {
        getline(cin, s);
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
          sum += ascii[(unsigned char)s.at(i)];//如果字符超过128，这里char会变成负数，索引负数指向的位置有问题
        }
      }
      printf("%.2lf$\n", sum / 100);
    }
    return 0;
}
