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

void build(int i, int l, int r)
{
  tree[i].l = l;
  tree[i].r = r;
  if (l == r) 
  {
    tree[i].m = node[l].e - node[l].s + 1;
    return ;
  }
  int mid = (l+r)>>1;
  build(2i, l, mid);
  build(2i+1, mid+1, r);
  tree[i] = max(tree[2i].m, tree[2i+1].m);
  return;
}
int query(int i, int l, int r)
{
  if (tree[i].l == l && tree[i].r == r) return tree[i].m;
  int mid = (tree[i].l + tree[i].r) >>1;
  if (r <= mid) return query(2i, l, r);
  else if (l > mid)
  {
    return query(2i+1, l, r);
  }
  else //l<= mid && r > mid
  {
    return max(query(2i, l, mid), query(2i+1, mid+1, r));
  }
}

