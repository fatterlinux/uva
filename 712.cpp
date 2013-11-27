#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
  int num_elm;
  int test_case = 1;
  while (cin >> num_elm && num_elm)
  {
    int cnt = 0;
    vector<int> order;
    while (cnt++ != num_elm)
    {
      string s;
      cin >> s;
      order.push_back(s[1] - '0');
    }
    string termi;
    cin >> termi;
    int num_val;
    cin >> num_val;
    cout << "S-Tree #" << test_case++ << ":" <<endl;
    while (num_val--)
    {
      string value;
      cin >> value;
      int idx = 1;
      for (int i = 0; i < order.size(); i++)
      {
        int non_elm = value[order[i] - 1] - '0';
        if (non_elm)
        {
          idx = idx*2 + 1;
        }
        else
        {
          idx = idx*2;
        }
      }
      int loc = idx - 1 - (pow(2, num_elm) - 1);
      cout << termi[loc];
    }
    cout << endl;
    cout << endl;
  }
  return 0;
}
