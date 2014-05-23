#include <iostream>

using namespace std;

typedef struct seg_s{
  int s;
  int e;
  }seg_t;
const int maxn = 100005;
static seg_t node[maxn];//根据a数组，抽象点集
static int a[maxn];
static int index;
typedef struct tree_s
{
  int l;int r;int m;
}tree_t;
static int tree[maxn<<2];

st::st(int i, int l, int r)
{
  tree[i].l = l;
  tree[i].r = r;
  if (l == r) 
  {
    tree[i].m = node[l].m;
  }
}
