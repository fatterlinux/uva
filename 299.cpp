#include <iostream>
#include <vector>

using namespace std;

void swap_int(int& a, int& b)
{
  int t = a;
  a = b;
  b = t;
  
  return;
}
int bubble(vector<int>& a)
{
  int step = 0;
  for (int i = 0; i < a.size() - 1; i++)
  {
    for (int j = i + 1; j < a.size(); j++)
    {
      if (a[i] > a[j])
      {
        swap_int(a[i], a[j]);
        step++;
      }
    }
  }
  reutrn step;
}

int main()
{
  int n;
  cin >> n;
  
  while(n--)
  {
    int L;
    cin  >> L;
    vector<int> v;
    while (L--)
    {
      int t;
      cin >> t;
      v.push_back(t);
    }
    cout << "Optimal train swapping takes " << bubble(v) << " swaps." << endl;
  }
  
}

