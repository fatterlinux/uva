#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;
const int max_n = 21;
int track[max_n];
int s[max_n][10000];
int f[10000];

int dp(int n, int v)
{
	if (s[n][v] >= 0) return s[n][v];
	if (n == 0) return s[n][v] = 0;
	int res1 = 0;
	int res2 = 0;
	if (track[n - 1] <= v)
	{
		res1 = dp(n - 1, v - track[n - 1]) + track[n - 1];
	}
	
	res2 = s[n][v] = dp(n - 1, v);

	if (res1 > res2)
	{
		f[n] = n;
	}
	else 
	{
		f[n] = n - 1;
	}
	return s[n][v] = max(res1, res2);
}
void print_path(int n, int v, int s)
{
	if (v == 0) return ;
	print_path(f[n], s[n][v] - track[f[n] - 1]);
	printf("%d ", track[f[n][v] - 1]);
}
int main()
{
#ifndef _ONLINE_JUDGE_
	freopen("624.in", "r", stdin);
#endif
	int value, number_tracks;
	while (scanf("%d %d", &value, &number_tracks) != EOF)
	{
		memset(track, 0, sizeof(track));
		memset(s, -1, sizeof(s));
		memset(f, -1, sizeof(f));
		for (int i = 0; i < number_tracks; i++)
		{
			scanf("%d", &track[i]);
		}
		int sss =  dp(number_tracks, value, sss);
		print_path(number_tracks, sss);
		cout << "sum:" << sss << endl;
	}
	return 0;
}
