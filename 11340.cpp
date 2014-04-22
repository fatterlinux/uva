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
        unsigned char c;
        int v;
        cin >> c >> v;
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
          sum += ascii[s.at(i)];
        }
      }
      printf("%.2lf$\n", sum / 100);
    }
    return 0;
}
