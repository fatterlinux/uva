#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

struct node
{
  double a, b, c;
  node()
  {
    a = b = c = 0;
  }
};

int distance_get(node& a, node& b)
{
  return int(sqrt(pow(a.a - b.a, 2) + pow(a.b - b.b, 2) + pow(a.c - b.c, 2)));
}
const int max_size = 5500;
node N[max_size];

int main()
{
  double a, b, c
  
}
