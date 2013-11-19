#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <string>

using namespace std;

struct node
{
  char data;
  node* l;
  node* r;
};

node* node_create(char data, node* l, node* t)
{
  node* t  = (node*)malloc(sizeof(*t));
  if (t)
  {
    t->data = data;
    t->l = l;
    t->r = r;
  }
  return t;
}
void node_free(node* t)
{
  if (!t) return;
  node_free(t->l);
  node_free(t->r);
  free(t);
  return ;
}

void bfs(node* t)
{
  if (!t) return;
  queue<node*> q;
  q.push(t);
  string s;
  while(!q.empty())
  {
    node* p = q.front();
    q.pop();
    
    if (p->l) q.push(p->l);
    if (p->r) q.push(p->r);
    s = p->data + s;
  }
  cout << s;
  return;
}

int main()
{
  int n;
  cin >> n;
  while (n--)
  {
    string s;
    cin >> s;
    for ()
  }
}
