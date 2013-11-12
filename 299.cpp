#include <iostream>
#include <vector>//用vector会超时...

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
        //swap_int(a[i], a[j]);
        int t = a[i];
        a[i] = a[j];
        a[j] = t; 
        step++;
      }
    }
  }
  return step;
}

int main()
{
  int n;
  cin >> n;
  
  while(n--)
  {
    int L;
    cin  >> L;
    //vector<int> v;
    int array[100];
    int array_len = 0;
    while (L--)
    {
      int t;
      cin >> t;
      //v.push_back(t);
      array[array_len++] = t;
    }
    int step = 0;
    for (int i = 0; i < array_len - 1; i++)
    {
      for (int j = i + 1; j < array_len; j++)
      {
        if (array[i] > array[j])
        {
          int t = array[i];
          array[i] = array[j];
          array[j] = t;
          step++;
        }
      }
    }
    cout << "Optimal train swapping takes " << step << " swaps." << endl;
  }
  
}

