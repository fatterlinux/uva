#include <iostream>

using namespace std;

class union_find
{
  public:
  union_find(int num)
  {
    id = new int[num+1];
    set = new int[num+1];
    for (int i = 0; i <= num; i++)
    {
      id[i] = i;
      set[i] = 1;
    }
  }
  int find(int p)
  {
    
  }
};
