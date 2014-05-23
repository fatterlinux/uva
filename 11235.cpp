#include <iostream>

using namespace std;

typedef struct seg_s{
  int s;
  int e;
  }seg_t;
const int maxn = 100005;
static seg_t node[maxn];//根据a数组，抽象点集
static int a[maxn], hash[maxn];
static int index;
typedef struct tree_s
{
  int l;int r;int m;
}tree_t;
static tree_t tree[maxn<<2];

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
  build(2*i, l, mid);
  build(2*i+1, mid+1, r);
  tree[i].m = max(tree[2*i].m, tree[2*i+1].m);
  return;
}
int query(int i, int l, int r)
{
  if (tree[i].l == l && tree[i].r == r) return tree[i].m;
  int mid = (tree[i].l + tree[i].r) >>1;
  if (r <= mid) return query(2*i, l, r);
  else if (l > mid)
  {
    return query(2*i+1, l, r);
  }
  else //l<= mid && r > mid
  {
    return max(query(2*i, l, mid), query(2*i+1, mid+1, r));
  }
}

int main()
{
  int m;
  while (cin >> m && m)
  {
    //缺少初始化
    int q;
    cin >>q;
    for (int i = 1 ; i <= m ; i++)
    {
      int t;
      cin >> t;
      a[i] = t;
    }
    int pre = maxn +100;//一个不会取到的数做离散初始化
    for (int i = 1; i <=m; i++)
    {
      if(a[i] != pre)
      {
        pre = a[i];
        index++;//不能是0，线段树找不到0索引,和tree的初始化有关系，都是从1开始的下标
        node[index].s = i;
        node[index].e = i;
      }
      else
      {
        node[index].e = i;
      }
      hash[i] = index;
    }
    build(1, 1, index);
    while (q--)
    {
      int x, y;
      cin >> x >> y;
      int xx = hash[x];
      int yy = hash[y];
      if (xx == yy)
      {
        cout << yy - xx + 1 << endl;
      }
      else
      {
        int ans1 = node[xx].e - x +1;
        int ans3 = y - node[yy].s + 1;
        int ans2 = 0;
        if (yy - xx > 1)//说明有3部分
        {
          ans2 = query(1, xx +1, yy -1);
        }
        int mm = max(max(ans1, ans2), ans3);
        cout <<mm<<endl;
      }
    }
  }
  return 0;
}
