#include <iostream>
#include <string>

using namespace std;

int main()
{
  int test_case;
  cin >>test_case;
  while (test_case--)
  {
    int len;
    cin >> len;
    int idx = 1;
    while (idx <= len)
    {
      if (idx % 2)//odd
      {
        
      }
      else //even
      {
        
      }
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    for (int i = 1; i <= len; i++)
    
    {
      if (i % 2)
      {
        cout << odd[i-1];
      }
      else
      {
        cout << even[i-1];
      }
    }
    cout <<endl;
  }
}
