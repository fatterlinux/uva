#include <stdio.h>
#include <sstream>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

const int max_size = 10050;
struct node
{
  int data;
  struct node* l;
  struct node* r;
  node()
  {
    data = 0;
    l = r = NULL;
  }
  void reset()
  {
    data = 0;
    l = r = NULL;
  }
};

struct node_pool
{
  node p[max_size];
  int idx;
  node_pool()
  {
    idx = 0;
  }
  node* alloc()
  {
    return &p[idx++];
  }
  void reset()
  {
    idx = 0;
    for (int i = 0; i < max_size; i++)
    {
      p[i].reset();
    }
  }
};
node_pool p;
int in[max_len];
int post[max_len];
node* build_tree(int in[], int post[], int len)
{
  if (0 == len) return NULL;
  node* root = p.alloc();
  int i = len - 1;
  while (post[len - 1] != in[i]) i--;
  root->data = post[len - 1];
  root->l = build_tree(in, post, i);
  root->r = build_tree(in + i + 1, post + i, len - i - 1);
  return root;
}
int path[max_size];
int path_leaf[max_size];
int path_idx;
void dfs(node* root, int sum)
{
  if (!root->l && !root->r)
  {
    path[path_idx] = sum + root->data;
    path_leaf[path_idx] = root->data;
    path_idx++;
    return;
  }
  if (root->l)
  {
    dfs(root->l, sum + root->data);
  }
  if (root->r)
  {
    dfs(root->r, sum + root->data);
  }
  return;
}
void out_put()
{
  int min = path[0];
  int min_idx = 0;
  for (int i = 1; i < path_idx; i++)
  {
    if (min > path[i])
    {
      min = path[i];
      min_idx = i;
    }
    else if (min == path[i] && path_leaf[min_idx] > path_leaf[i])
    {
      min = path[i];
      min_idx = i;
    }
  }
  printf("%d", min_idx);
}
void init()
{
  memset(path, 0, sizeof(path));
  memset(path_leaf, 0, sizeof(path_leaf));
  path_idx = 0;
  p.reset();
  memset(in, 0, sizeof(in));
  memset(post, 0, sizeof(post));
}

int main()
{
  string s;
  while (getline(cin ,s))
  {
    init();
    stringstream ss;
    int i = 0;
    int elm;
    ss << s;
    while (ss >> elm)
    {
      in[i++] = elm;
    }
    getline(cin, s);
    ss << s;
    i = 0;
    while (ss >> elm)
    {
      post[i++] = elm;
    }
    node* root = build_tree(in, post, sizeof(in)/sizeof(in[0]));
    dfs(root);
    output();
  }
  return 0;
}
