#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;
  while (cin >> s)
  {
    if (s == "0")
    {
      break;
    }
    
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
      sum += (s[i] - '0')*((1 << (s.size() - i)) - 1); 
    }
    cout << sum << endl;
  }
  return 0;
}
