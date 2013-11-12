#include <iostream>
#include <sstream>

using namespace std;

void filp(int arr[], int arr_len, int loc)
{
  int bottom = arr_len - loc;
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
  
}
