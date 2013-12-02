#include <stdion.h>

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
  reset()
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
  alloc()
  {
    return &p[idx++];
  }
  reset()
  {
    idx = 0;
    for (int i = 0; i < max_size; i++)
    {
      p[i].reset();
    }
  }
};
node_pool p;
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
