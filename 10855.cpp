#include <iostream>

int** rotated_90(const int a[][], int m)
{
  int** b = new [m][m];
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < m; j++)
    {
      b[i][j] = a[m-j-1][m-i-1];
    }
  }
  return b;
}
void rotated_180(int a[][], int b[][], int m)
{
  int** b = rotated_90(a,m);
  int** c = rotated_90(b,m);
  delete [] b;
}
