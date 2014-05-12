#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int test_case;
  cin >> test_case;
  while(test_case--)
  {
    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
      int snowflake;
      cin >> snowflake;
      v.push_back(snowflake);
    }
    sort(v.begin(), v.end());
    vector<int>::iterator iter = unique(v.begin(), v.end());
    v.erase(iter, v.end());
    cout << v.size() << endl;
  }
}

