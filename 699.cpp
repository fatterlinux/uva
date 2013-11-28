#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <sstream>

using namespace std;

void solve(vector<int>& seq, int res[]);
int main()
{
  while (1)
  {
    vector<int> seq;
    string s;
    getline(cin , s);
    stringstream ss(s);
    int e;
    if (ss >> e)
    {
      if (e == -1)
      {
        break;
      }
    }
    seq.push_back(e);
    while (ss >> e)
    {
      seq.push_back(e);
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
  while (res[idx++] == 0);
  static int cnt = 1;
  cout << "Case " << cnt++ << ":" << endl;
  bool first = true;
  for (; idx < 1000; idx++)
  {
    if (first)
    {
      first = false;
    }
    else
    {
      cout <<" ";
    }
    if (res[idx] == 0) break;
    cout << res[idx];
  }
  cout << endl;
  cout << endl;
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
void solve(vector<int>& seq, int res[])
{
  int seq_idx = 0;
  node* root = build(seq, seq_idx);
  bfs(root, res, 500);
  output(res);
}
