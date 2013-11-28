#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

void solve(vector<int>& seq, int res[]);
int main()
{
  while (1)
  {
    vector<int> seq;
    int e;
    if (cin >> e)
    {
      if (e == -1)
      {
        break;
      }
    }
    seq.push_back(e);
    while (cin >> e)
    {
      seq.push_back(e);
    }
    int res[1000];
    memset(res, -1, sizeof(res));
    solve(seq, res);
  }
  return 0;
}

void solve(vector<int>& seq, int res[])
{
  int seq_idx = 0;
  node* root = build(seq, seq_idx);
  bfs(root, res);
  output(res);
}
