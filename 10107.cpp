#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  vector<int> v;
  
  while (cin >> n)
  {
    v.push_back(n);
    sort(v.begin(), v.end());
    int size = v.size();
    if (size % 2 == 0)
    {
      cout << (v[(size-1)/2] + v[(size-1)/2+1])/2 << endl;
    }
    else
    {
      cout << v[(size-1)/2] << endl;
    }
  }
  return 0;
}
