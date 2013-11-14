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
    cout << sep << endl;
    vector<string> v;
    int word_num = n;
    while (n--)
    {
      string s;
      cin >> s;
      v.push_back(s);
    }
    sort(v.begin(), v.end());
    int len = 0;
    for (int i = 0; i < v.size(); i++)
    {
      if (v[i].size() > len)
      {
        len = v[i].size();
      }
    }
    int row = (max_len - len) / (2*len) + 1;//关键，计算一行存储的单词数
    int column = word_num / row + (word_num % row ? 1 : 0);//输出的行数
    for (int i = 0; i < column; i++)
    {
      for (int j = 0; j < row; j++)
      {
        if ((j*column+i) < v.size())
        {
          string res = v[j*column+i];
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
