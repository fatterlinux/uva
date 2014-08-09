#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;
const int max_n = 21;
int track[max_n];
int s[max_n][100000];

int dp(int n, int v)
{
	if (s[n][v] >= 0) return s[n][v];
	if (n == 0) return s[n][v] = 0;
	if (track[n - 1] <= v)
	{
		return s[n][v] = max(dp(n - 1, v), (track[n-1] + dp(n - 1, v-track[n-1])));
	}
	else
	{
		return s[n][v] = dp(n - 1, v);
	}
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
		for (int i = 0; i < number_tracks; i++)
		{
			scanf("%d", &track[i]);
		}
		cout << "sum:" << dp(number_tracks, value) << endl;
	}
	return 0;
}
