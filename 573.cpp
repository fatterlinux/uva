#include <stdio.h>
//蜗牛在爬行时速度会随着疲劳度降至0，此时蜗牛就不会爬行了，会一直往下滑
//自己想多了，以为今天蜗牛累了不爬了，明天就会有体力重新爬了囧
int main()
{
#ifndef ONLINE_JUDGE
	freopen("573.in", "r", stdin);
	freopen("573.out", "w", stdout);
#endif
	int h, u, d, f;
	while (scanf("%d %d %d %d", &h, &u, &d, &f), h)
	{
		int days = 0;
        int successive = 0;
		double climb_feets = 0;
		double f_percent = f * 0.01;
		while (1)
		{
			days++;
            successive++;
            //printf("%lf %lf %lf %lf\n", climb_feets, u - (days - 1) * f_percent, climb_feets + u - (days - 1) * f_percent, climb_feets + u - (days - 1) * f_percent - d);
			//白天爬行
            if ( (u - (successive - 1) * f_percent * u) >= 0)
            {
                climb_feets += u - (successive - 1) * f_percent * u;
            }
			if (climb_feets > h)
			{
				printf("success on day %d\n", days);
				break;
			}
			climb_feets -= d;
			if (climb_feets < 0)
			{
				printf("failure on day %d\n", days);
				break;
			}
            
		}
	}
	return 0;
}
