#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <sstream>

using namespace std;
//Case 2 和Case 3 是一组数据，注意了
//好吧，这里一个case可以换行的
void solve(vector<int>& seq, int res[]);
int main()
{
  while (1)
  {
    vector<int> seq;
    //string s;
    //getline(cin , s);
    //stringstream ss(s);
    int e;
    if (cin >> e)
    {
      if (e == -1)
      {
        break;
      }
    }
    seq.push_back(e);
    int a1 = 1;
    int a2 = 0;
    while (cin >> e)
    {
      seq.push_back(e);
      if (e >0) a1++;
      else
      {
        a2++;
      }
      if (a1 +1 = a2)
      {
        break;
      }
    }
    int res[1000];
    memset(res, 0, sizeof(res));
    solve(seq, res);
  }
  return 0;
}

void output(int res[])
{
  int idx = 0;
  while (res[idx] == 0) idx++;
  static int cnt = 1;
  cout << "Case " << cnt++ << ":" << endl;
  bool first = true;
  stringstream s;
  for (; idx < 1000; idx++)
  {
    if (res[idx] == 0) break;
    if (first)
    {
      first = false;
    }
    else
    {
      s <<" ";
    }
    s << res[idx];
  }
  s << endl;
  s << endl;
  cout << ss.c_str();
}
struct node
{
  int value;
  struct node *l, *r;
};
node* build(vector<int>& seq, int& idx)
{
  if (idx >= seq.size())return NULL;
  if (seq[idx] == -1)return NULL;
  node* root =(node*) malloc(sizeof(*root));
  assert(NULL != root);
  root->value = seq[idx];
  idx++;
  root->l = build(seq, idx);
  idx++;
  root->r = build(seq, idx);
  return root;
}
void bfs(node* root, int res[], int idx)
{
  if (root)
  {
    res[idx] += root->value;
    bfs(root->l, res, idx-1);
    bfs(root->r, res, idx+1);
  }
  return;
}
void tree_free(node* root)
{
  if (root)
  {
    tree_free(root->l);
    tree_free(root->r);
    free(root);
  }
  return;
}
void solve(vector<int>& seq, int res[])
{
  int seq_idx = 0;
  node* root = build(seq, seq_idx);
  bfs(root, res, 500);
  output(res);
  tree_free(root);
}
