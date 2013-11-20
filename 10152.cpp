#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int test_case;
  cin >> test_case;
  
  while (test_case--)
  {
    int turtle_num;
    string t
    getline(cin, t);
    cin >> turtle_num;
    vector<string> v1;
    vector<string> v2;
    int cnt = turtle_num;
    while (cnt--)
    {
      string s;
      getline(cin, s);
      v1.push_back(s);
    }
    cnt = turtle_num;
    while (cnt--)
    {
      string s;
      getline(cin, s);
      v2.push_back(s);
    }
    int i = j = v1.size() - 1;
    for (; i >= 0; )
    {
      if (v1[i] == v2[j])
      {
        i--;
        j--;
      }
      else
      {
        i--;
      }
    }
    while (j >= 0)
    {
      cout << v2[j--] << endl;
    }
    cout << endl;
  }
  return 0;
}
