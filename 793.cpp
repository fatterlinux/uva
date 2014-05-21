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
    while (id[p] != p) p = id[p];
    return p;
  }
  bool connected(int p, int q)
  {
    return find(p) == find(q);
  }
  void union(int p, int q)
  {
    int parent_p = find(p);
    int parent_q = find(q);
    if (parent_p == parent_q) return;
    if (set[parent_p] > set[parent_q])
    {
      id[parent_q] = parent_p;
      set[parent_p] += set[parent_q];
    }
    else
    {
      id[parent_p] = parent_q;
      set[parent_q] += set[parent_p];
    }
  }
  ~union_find()
  {
    delete [] id;
    delete [] set;
  }
  private:
  int[] id;
  int[] set;
};
