#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int max_len = 60;
const string sep(max_len, '-');
int main()
{
  int n;
  while (cin >> n)
  {
    cout << seq << endl;
    vector<string> v;
    while (n--)
    {
      string s;
      cin >> s;
      v.push_back(s);
    }
    sort(v.begin(), v.end());
    int len = v[v.size()-1].size();
    int row = (max_len - len) / 2 + 1;//关键，计算一行存储的单词数
    int column = n / row + 1;//输出的行数
    for (int i = 0; i < column; i++)
    {
      for (int j = 0; j < row; j++)
      {
        if (j + column < v.size())
        {
          string res = v[j + column];
          int space_len = len - res.size();
          cout << res;
          for (int k = 0; k < space_len; k++)
          {
            cout << " ";
          }
        }
      }
      cout << endl;
    }
  }
}
