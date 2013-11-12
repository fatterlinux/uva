#include <iostream>
#include <sstream>

using namespace std;

void filp(int arr[], int arr_len, int loc)
{
  int bottom = loc;
  for (int i = 0; i <= bottom/2; i++)
  {
    int t = arr[i];
    arr[i] = arr[bottom - i];
    arr[bottom - i] = t;
  }
  return;
}

int main()
{
  string s;
  while (getline(cin, s))
  {
    stringstream ss(s);
    int a;
    int arr[40];
    int idx = 0;
    while (ss >> a)
    {
      arr[idx++] = a;
    }
    for (int i = 0; i < idx; i++)
    {
      if (i) cout <<" ";
      cout << arr[i];
    }
    cout << endl;
    bool first = true;
    for (int i = idx - 1; i > 0; i--)
    {
      int max_idx = 0;
      for (int j = 1; j <= i; j++)
      {
        if (arr[max_idx] < arr[j])
        {
          max_idx = j;
        }
      }
      if (max_idx != i)
      {
        if (max_idx != 0)//bottom idx
        {
          filp(arr, idx, max_idx);
          if (first) first = false;
          else
          {
            cout <<" ";
          }
          cout << idx - max_idx;
        }
        filp(arr, idx, i);
        if (first) first = false;
        else
        {
          cout << " ";
        }
        cout << idx - i;
      }
    }
    if (!first) cout << " ";
    cout << 0 <<endl;
  }
  return 0;
}
