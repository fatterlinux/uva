#include <iostream>
#include <bitset>

const int max_size = 1000000001;
using namespace std;

bitset<max_size> b;

int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    b.reset();
    int m;
    cin >> m;
    while (m--)
    {
      int snowflake;
      cin >> snowflake;
      b.set(snowflake);
    }
    cout << b.count << endl;
  }
  return 0;
}


